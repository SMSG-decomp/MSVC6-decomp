c2_operand * __fastcall get_tied_source_operand(c2_tuple *t)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  
  uVar1 = t->op;
  if (((uVar1 == 0x166) && (pcVar2 = t->src, (pcVar2->u18).reg == (c2_symbol *)0x183)) &&
     (pcVar2->tag == 0)) {
    return pcVar2->next;
  }
  if (uVar1 == 0x178) {
    return t->src;
  }
  if ((g_x86_op_flags[uVar1] & 0x40) != 0) {
    return t->src;
  }
  pcVar2 = operand_list_find_reg(t->src,(t->dst->u18).reg);
  return pcVar2;
}

