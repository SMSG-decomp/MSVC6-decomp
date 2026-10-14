c2_operand * __fastcall tuple_append_dst(c2_tuple *t,c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  if ((1 << (op->kind & 0x1f) & 0xffeU) != 0) {
    if ((op->flags & 0x10) != 0) {
      op = (c2_operand *)node_clone((c2_node *)op);
    }
    op->flags = op->flags | 0x10;
  }
  pcVar2 = t->dst;
  if (t->dst != (c2_operand *)0x0) {
    do {
      pcVar1 = pcVar2;
      pcVar2 = pcVar1->next;
    } while (pcVar1->next != (c2_operand *)0x0);
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->next = op;
      goto LAB_1070444a;
    }
  }
  t->dst = op;
LAB_1070444a:
  pcVar2 = (c2_operand *)0x0;
  if (((1 << (op->kind & 0x1f) & 0x60U) != 0) && ((op->flags11 & 0x20) == 0)) {
    pcVar1 = op->base;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      pcVar2 = tuple_append_src(t,pcVar1);
    }
    pcVar1 = op->index;
    if (pcVar1 != (c2_operand *)0x0) {
      pcVar1->flags = pcVar1->flags & 0xef;
      pcVar2 = tuple_append_src(t,pcVar1);
    }
  }
  return pcVar2;
}

