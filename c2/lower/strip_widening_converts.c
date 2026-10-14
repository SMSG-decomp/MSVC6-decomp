c2_operand * __fastcall strip_widening_converts(c2_operand *op,uint32_t flags)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_operand *node;
  
  if (((1 << (op->kind & 0x1f) & 6U) == 0) || (op->sym->def == (c2_tuple *)0x0)) {
    return op;
  }
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    while ((pcVar2 = op->sym->def, pcVar2 != (c2_tuple *)0x0 && (pcVar2->op == 0x15f))) {
      node = pcVar2->src;
      uVar1 = node->type;
      if ((pcVar2->type & 0xfff) <= (uVar1 & 0xfff)) {
        return op;
      }
      if (((flags & 1) == 0) && ((uVar1 & 0xf000) != 0x2000)) {
        return op;
      }
      if ((1 << (byte)(uVar1 >> 0xc) & 0xeU) == 0) {
        return op;
      }
      if ((flags & 2) != 0) {
        node = (c2_operand *)node_clone((c2_node *)node);
        tuple_unlink_free(op->sym->def);
      }
      op = node;
      if ((1 << (node->kind & 0x1f) & 6U) == 0) {
        return node;
      }
    }
  }
  return op;
}

