c1_node * __cdecl tree_new_rvalue(c1_node *n)

{
  c1_type *pcVar1;
  c1_node *node;
  byte bVar2;
  ushort uVar3;
  
  if (n == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  node = tree_new_unary('=',n->type,n);
  bVar2 = (n->flags ^ node->flags) & 1 ^ node->flags;
  node->flags = bVar2;
  pcVar1 = node->type;
  bVar2 = (n->flags ^ bVar2) & 4 ^ bVar2;
  node->flags = bVar2;
  node->flags = (pcVar1->code & 0xfff) == 0x10 | bVar2;
  if (((pcVar1->code & 0x8f) == 0x82) &&
     ((uVar3 = pcVar1->flags & 0x18, uVar3 == 0x18 || (uVar3 == 8)))) {
    node = expr_based_pointer_fixup(node);
  }
  return node;
}

