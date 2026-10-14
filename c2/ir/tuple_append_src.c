c2_operand * __fastcall tuple_append_src(c2_tuple *t,c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  if ((1 << (op->kind & 0x1f) & 0xffeU) != 0) {
    if ((op->flags & 0x10) != 0) {
      op = (c2_operand *)node_clone((c2_node *)op);
    }
    op->flags = op->flags | 0x10;
  }
  pcVar1 = t->src;
  if (t->src != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2->next;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar2->next = op;
      goto LAB_107029a6;
    }
  }
  t->src = op;
LAB_107029a6:
  if (((1 << (op->kind & 0x1f) & 0x60U) != 0) && ((op->flags11 & 0x20) == 0)) {
    pcVar1 = op->base;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(t,pcVar1);
    }
    pcVar1 = op->index;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      tuple_append_src(t,pcVar1);
    }
  }
  return op;
}

