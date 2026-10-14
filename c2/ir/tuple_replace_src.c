c2_operand * __fastcall tuple_replace_src(c2_tuple *t,c2_operand *old,c2_operand *new_op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_operand *pcVar4;
  
  if ((1 << (new_op->kind & 0x1f) & 0xffeU) != 0) {
    if ((new_op->flags & 0x10) != 0) {
      new_op = (c2_operand *)node_clone((c2_node *)new_op);
    }
    new_op->flags = new_op->flags | 0x10;
  }
  new_op->next = old->next;
  old->next = new_op;
  if (((1 << (old->kind & 0x1f) & 0xffeU) != 0) && ((old->flags & 0x20) != 0)) {
    mem_operand_replace_subop(t,old,new_op);
  }
  pcVar1 = t->src;
  pcVar4 = (c2_operand *)0x0;
  if (t->src != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      if (pcVar2 == old) break;
      pcVar1 = pcVar2->next;
      pcVar4 = pcVar2;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar4 != (c2_operand *)0x0) {
      pcVar4->next = old->next;
      goto LAB_1070219c;
    }
  }
  t->src = old->next;
LAB_1070219c:
  if ((1 << (old->kind & 0x1f) & 0x60U) != 0) {
    tuple_remove_mem_subops(t,old);
  }
  node_free((c2_node *)old);
  uVar3 = 1 << (new_op->kind & 0x1f);
  if ((((uVar3 & 0xffe) != 0) && ((uVar3 & 0x60) != 0)) && ((new_op->flags11 & 0x20) == 0)) {
    pcVar1 = new_op->base;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(t,pcVar1);
    }
    pcVar1 = new_op->index;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(t,pcVar1);
    }
  }
  return new_op;
}

