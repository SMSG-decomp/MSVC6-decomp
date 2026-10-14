void __cdecl eh_mark_state_nodes_in_tree(c1_node *node)

{
  byte *pbVar1;
  byte bVar2;
  uint *arg;
  uint *arg_list;
  
  if (node == (c1_node *)0x0) {
    return;
  }
  do {
    bVar2 = node->kind & 7;
    if (bVar2 == 2) {
      if (node->op == 0xc1) {
        if ((g_eh_state_table[*(int *)((int)node->left + 0x10)].kind == 6) ||
           (g_eh_state_table[*(int *)((int)node->left + 0x10)].kind == 2)) {
          pbVar1 = (byte *)((int)node->left + 0x16);
          *pbVar1 = *pbVar1 | 0x40;
          node = node->right;
          goto LAB_10419764;
        }
      }
      eh_mark_state_nodes_in_tree(node->left);
      node = node->right;
    }
    else if (bVar2 == 1) {
LAB_104197ad:
      node = node->left;
    }
    else {
      if (bVar2 == 0) {
        if ((node->op != 0xc2) && (node->op != 0xc3)) {
          return;
        }
        if ((g_eh_state_table[(int)node->left].kind != 6) &&
           (g_eh_state_table[(int)node->left].kind != 2)) {
          return;
        }
        pbVar1 = (byte *)((int)&node->right + 2);
        *pbVar1 = *pbVar1 | 0x40;
        return;
      }
      if (bVar2 != 7) {
        return;
      }
      bVar2 = node->op;
      if (0xb4 < bVar2) {
        if (bVar2 < 0xb7) {
          for (arg_list = node->right; arg_list != (uint *)0x0; arg_list = (uint *)*arg_list) {
            for (arg = (uint *)arg_list[1]; arg != (uint *)0x0; arg = (uint *)*arg) {
              eh_mark_state_nodes_in_tree((c1_node *)arg[1]);
            }
          }
          goto LAB_104197ad;
        }
        if (bVar2 == 0xb7) {
          return;
        }
      }
    }
LAB_10419764:
    if (node == (c1_node *)0x0) {
      return;
    }
  } while( true );
}

