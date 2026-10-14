c2_tuple * __fastcall
emit_sign_extend_high(uint16_t type,c2_tuple *anchor,c2_operand *high_reg,c2_operand **value)

{
  int iVar1;
  c2_tuple *t;
  c2_operand *pcVar2;
  
  iVar1 = (int)(type & 0xfff) >> 1;
  t = tuple_new_unary_temp
                (g_sign_extend_opcode_by_size[iVar1],type,*value,tuple_insert_after,anchor);
  if ((high_reg->u18).reg == g_reg_symbols + 0x15) {
    pcVar2 = operand_retype(t->dst,t->type & 0xf002 | 2,0);
    *value = pcVar2;
    pcVar2->sym->def = t;
  }
  else {
    high_reg->u18 = *(c2_operand_u18 *)(g_divide_high_reg_by_size + iVar1);
    tuple_append_dst(t,high_reg);
    high_reg->sym->def = t;
  }
  pcVar2 = t->dst;
  *value = pcVar2;
  pcVar2->u18 = *(c2_operand_u18 *)(g_divide_low_reg_by_size + (pcVar2->type >> 1 & 0x7ff));
  return t;
}

