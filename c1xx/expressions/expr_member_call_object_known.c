int __cdecl expr_member_call_object_known(c1_node *access)

{
  c1_node *node;
  c1_node *node_00;
  c1_symbol *pcVar1;
  int iVar2;
  
  node = access->left;
  if (node != (c1_node *)0x0) {
    node_00 = node;
    if (node->op == 'S') {
      node_00 = node->left;
    }
    pcVar1 = expr_find_base_symbol(node_00);
    if (pcVar1 != (c1_symbol *)0x0) {
      return CONCAT31((int3)((uint)pcVar1 >> 8),1);
    }
    access = (c1_node *)0x0;
    if (g_current_function != (c1_symbol *)0x0) {
      if (((g_current_function->flags1 & 0x10) == 0x10) ||
         (access = (c1_node *)
                   (CONCAT31((int3)((uint)g_current_function >> 8),g_current_function->flags1) &
                   0xffffff20), (char)access == ' ')) {
        iVar2 = tree_is_this_read(node);
        access = (c1_node *)0x0;
        if (iVar2 != 0) {
          return CONCAT31((int3)((uint)iVar2 >> 8),1);
        }
      }
    }
  }
  return (uint)access & 0xffffff00;
}

