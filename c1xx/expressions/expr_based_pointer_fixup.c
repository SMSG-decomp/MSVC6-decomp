c1_node * __cdecl expr_based_pointer_fixup(c1_node *node)

{
  c1_type *type;
  bool bVar1;
  c1_node *pcVar2;
  char *b;
  ushort uVar3;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  type = node->type;
  if (-1 < (char)type->code) {
    return node;
  }
  uVar3 = type->flags & 0x18;
  if ((uVar3 != 0x18) && (uVar3 != 8)) {
    return node;
  }
  pcVar2 = type_based_base(type);
  b = (char *)expr_find_based_base(node);
  if (b != (char *)0x0) {
    bVar1 = expr_same_based_base(pcVar2,b);
    if (bVar1) {
      return node;
    }
  }
  if (pcVar2 == (c1_node *)0x0) {
    return node;
  }
  pcVar2 = tree_new_binary(']',node,pcVar2);
  return pcVar2;
}

