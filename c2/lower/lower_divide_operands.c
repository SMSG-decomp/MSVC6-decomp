void __fastcall lower_divide_operands(c2_tuple *t,c2_symbol *reg,int is_unsigned)

{
  ushort type;
  c2_register_descriptor *pcVar1;
  c2_tuple *pos;
  int iVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_symbol *sym;
  c2_operand *new_op;
  c2_operand *local_8;
  c2_symbol *local_4;
  
  local_4 = reg;
  iVar2 = tuple_reads_eax_not_first(t);
  if (iVar2 == 0) {
    local_8 = t->src;
    type = t->type;
    pcVar4 = local_8->sym->def;
    pcVar3 = operand_new_temp(type);
    pcVar1 = g_divide_high_reg_by_size[type >> 1 & 0x7ff];
    (pcVar3->u18).reg = pcVar1;
    if (pcVar1 != g_reg_symbols + 0x15) {
      tuple_append_src(t,pcVar3);
    }
    if (is_unsigned == 0) {
      pcVar4 = emit_sign_extend_high(t->type,pcVar4,pcVar3,&local_8);
      tuple_replace_src(t,t->src,local_8);
    }
    else {
      pcVar4 = build_zero_extend_int64(pcVar3,pcVar4,0,1);
    }
    tuple_move_eax_src_last(t);
    if ((t->type & 0xfff) != 1) {
      pcVar3 = operand_new_hardreg(local_4->id,t->type);
      tuple_append_dst(t,pcVar3);
      return;
    }
    pcVar3 = t->dst;
    sym = symbol_get_part(pcVar3->sym,0x1002,2,0);
    new_op = operand_new_reg(0x149,0x1002,sym,g_reg_symbols + 9);
    tuple_replace_dst(t,pcVar3,new_op);
    if (is_unsigned != 0) {
      pos = pcVar4->prev;
      tuple_unlink(pcVar4);
      tuple_insert_before(pos,pcVar4);
      tuple_append_src(pos,pcVar4->dst);
    }
  }
  return;
}

