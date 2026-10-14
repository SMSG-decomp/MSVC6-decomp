c2_operand * __fastcall operand_claim(c2_operand *op)

{
  if ((1 << (op->kind & 0x1f) & 0xffeU) != 0) {
    if ((op->flags & 0x10) != 0) {
      op = (c2_operand *)node_clone((c2_node *)op);
    }
    op->flags = op->flags | 0x10;
  }
  return op;
}

