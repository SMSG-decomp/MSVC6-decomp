void __cdecl eh_collect_state_markers(int *list_head,c1_node *tree,char no_stamp)

{
  void *pvVar1;
  byte bVar2;
  uint *arg;
  uint *arg_list;
  
  if (tree != (c1_node *)0x0) {
    while( true ) {
      bVar2 = tree->kind & 7;
      if (bVar2 == 2) {
        if (tree->op == 0xc1) {
          node_list_push(list_head,(int)tree);
          if (no_stamp == '\0') {
            pvVar1 = tree->left;
            if (g_eh_state_table[*(int *)((int)pvVar1 + 0x10)].kind == 1) {
              *(ushort *)((int)pvVar1 + 0x14) = *(ushort *)((int)pvVar1 + 0x14) & 0xfff | 0x4000;
            }
            else {
              *(ushort *)((int)pvVar1 + 0x14) =
                   *(ushort *)((int)pvVar1 + 0x14) & 0xfff |
                   (short)g_eh_state_table[*(int *)((int)pvVar1 + 0x10)].kind << 0xc;
            }
            if ((*(ushort *)((int)tree->left + 0x14) & 0xf000) == 0x4000) {
              g_eh_state_table[*(int *)((int)tree->left + 0x10)].unwound = '\x01';
              tree = tree->right;
              goto LAB_1041a01b;
            }
          }
        }
        else {
          eh_collect_state_markers(list_head,tree->left,no_stamp);
        }
        tree = tree->right;
        goto LAB_1041a01b;
      }
      if (bVar2 == 1) goto LAB_1041a036;
      if (bVar2 == 0) break;
      if (bVar2 != 7) {
        return;
      }
      bVar2 = tree->op;
      if (0xb4 < bVar2) {
        if (bVar2 < 0xb7) {
          for (arg_list = tree->right; arg_list != (uint *)0x0; arg_list = (uint *)*arg_list) {
            for (arg = (uint *)arg_list[1]; arg != (uint *)0x0; arg = (uint *)*arg) {
              eh_collect_state_markers(list_head,(c1_node *)arg[1],no_stamp);
            }
          }
        }
        else if (bVar2 != 0xb7) goto LAB_1041a01b;
LAB_1041a036:
        tree = tree->left;
      }
LAB_1041a01b:
      if (tree == (c1_node *)0x0) {
        return;
      }
    }
    if (((tree->op == 0xc2) || (tree->op == 0xc3)) &&
       (node_list_push(list_head,(int)tree), no_stamp == '\0')) {
      *(ushort *)&tree->right =
           (short)g_eh_state_table[(int)tree->left].kind << 0xc | *(ushort *)&tree->right & 0xfff;
    }
  }
  return;
}

