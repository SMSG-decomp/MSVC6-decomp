byte __cdecl expr_is_zero_constant(c1_node *node)

{
  if (node == (c1_node *)0x0) {
    return 0;
  }
  if ((node->kind & 7) != 3) {
    return 0;
  }
  if (node->op != 'e') {
    return 0;
  }
  if (((byte)node->type->code >> 4 & 1) != 0) {
    return node->kind >> 7;
  }
  return 0;
}

