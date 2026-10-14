uint32_t __fastcall tuple_remove_src(c2_tuple *t,c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  c2_operand *pcVar4;
  
  pcVar1 = t->src;
  pcVar4 = (c2_operand *)0x0;
  if (t->src != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      if (pcVar2 == op) break;
      pcVar1 = pcVar2->next;
      pcVar4 = pcVar2;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar4 != (c2_operand *)0x0) {
      pcVar4->next = op->next;
      goto LAB_1070371f;
    }
  }
  t->src = op->next;
LAB_1070371f:
  if ((1 << (op->kind & 0x1f) & 0x60U) != 0) {
    tuple_remove_mem_subops(t,op);
  }
  uVar3 = node_free((c2_node *)op);
  return uVar3;
}

