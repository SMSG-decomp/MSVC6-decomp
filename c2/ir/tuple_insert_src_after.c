c2_operand * __fastcall tuple_insert_src_after(c2_tuple *t,c2_operand *after,c2_operand *op)

{
  c2_operand *pcVar1;
  uint uVar2;
  
  if ((1 << (op->kind & 0x1f) & 0xffeU) != 0) {
    if ((op->flags & 0x10) != 0) {
      op = (c2_operand *)node_clone((c2_node *)op);
    }
    op->flags = op->flags | 0x10;
  }
  op->next = after->next;
  uVar2 = 1 << (op->kind & 0x1f);
  after->next = op;
  if ((((uVar2 & 0xffe) != 0) && ((uVar2 & 0x60) != 0)) && ((op->flags11 & 0x20) == 0)) {
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

