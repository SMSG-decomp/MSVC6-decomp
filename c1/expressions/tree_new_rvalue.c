c1_node * __cdecl tree_new_rvalue(c1_node *operand)

{
  c1_node *node;
  ushort uVar1;
  
  if (operand == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  node = tree_new_unary('=',operand->type,operand);
  if (((node->type->code & 0x8f) == 0x82) &&
     ((uVar1 = node->type->flags & 0x18, uVar1 == 0x18 || (uVar1 == 8)))) {
    node = expr_based_pointer_fixup(node);
  }
  return node;
}

