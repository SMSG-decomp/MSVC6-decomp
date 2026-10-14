void __fastcall compute_operand_constraints(c2_tuple *t,uint32_t *out)

{
  byte bVar1;
  uint uVar2;
  c2_operand *pcVar3;
  c2_operand *opnd;
  c2_operand *pcVar4;
  
  uVar2 = t->op;
  pcVar3 = t->dst;
  opnd = pcVar3;
  if ((((uVar2 != 0) && (uVar2 < 0x144)) && ((g_x86_op_flags[uVar2] & 0x40) != 0)) &&
     ((pcVar3->kind == '\x01' && (((pcVar3->u18).reg)->storage == g_reg_symbols + 0x42)))) {
    pcVar4 = t->src;
    opnd = (c2_operand *)node_clone((c2_node *)pcVar4);
    if (pcVar4->kind != '\x01') {
      bVar1 = opnd->flags;
      opnd->next = pcVar3;
      t->dst = opnd;
      opnd->flags = bVar1 | 0x10;
    }
  }
  pcVar3 = t->src;
  if (pcVar3 == (c2_operand *)0x0) {
    pcVar4 = (c2_operand *)0x0;
  }
  else {
    pcVar4 = pcVar3->next;
  }
  operand_constraints_by_opcode(t,opnd,pcVar3,pcVar4,out);
  if (opnd != t->dst) {
    node_free((c2_node *)opnd);
  }
  return;
}

