int __cdecl expr_count_call_arguments(c1_node *node2)

{
  int iVar1;
  
  iVar1 = 0;
  if (node2 != (c1_node *)0x0) {
    while( true ) {
      iVar1 = iVar1 + 1;
      if ((node2->kind & 8) != 0) break;
      if ((node2->kind & 7) != 2) {
        return iVar1;
      }
      node2 = node2->right;
      if (node2 == (c1_node *)0x0) {
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

