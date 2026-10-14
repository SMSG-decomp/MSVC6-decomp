c2_operand * __fastcall tuple_replace_dst(c2_tuple *t,c2_operand *old,c2_operand *new_op)

{
  c2_operand *pcVar1;
  
  if ((1 << (new_op->kind & 0x1f) & 0xffeU) != 0) {
    if ((new_op->flags & 0x10) != 0) {
      new_op = (c2_operand *)node_clone((c2_node *)new_op);
    }
    new_op->flags = new_op->flags | 0x10;
  }
  new_op->next = old->next;
  old->next = new_op;
  tuple_remove_dst(t,old);
  if (((1 << (new_op->kind & 0x1f) & 0x60U) != 0) && ((new_op->flags11 & 0x20) == 0)) {
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

