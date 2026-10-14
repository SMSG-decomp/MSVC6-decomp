c1_node * __cdecl
expr_build_binary_fragment(c1_node *inner,c1_type *type,c1_node *node,c1_node *left,c1_node *right)

{
  c1_type *pcVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  
  node->left = inner->left;
  uVar2 = *(uint *)((int)left->right + 0x10);
  pvVar3 = right->left;
  iVar4 = *(int *)((int)left->right + 0x14);
  right->left = (void *)((int)pvVar3 + uVar2);
  right->right = (void *)((int)right->right + (uint)CARRY4((uint)pvVar3,uVar2) + iVar4);
  pcVar1 = type->base;
  node->type = pcVar1;
  if ((pcVar1->code & 0x8f) != 0x83) {
    node = tree_new_rvalue(node);
  }
  return node;
}

