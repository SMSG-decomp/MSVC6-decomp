void __cdecl eh_merge_state_markers(c1_node *node)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  char *pcVar8;
  c1_node *pcVar9;
  uint *arg;
  uint *arg_list;
  
  if (node != (c1_node *)0x0) {
    while (bVar6 = node->kind & 7, bVar6 != 2) {
      if (bVar6 != 1) {
        if (bVar6 != 7) {
          return;
        }
        if (node->op < 0xb5) {
          return;
        }
        if (0xb6 < node->op) {
          return;
        }
        for (arg_list = node->right; arg_list != (uint *)0x0; arg_list = (uint *)*arg_list) {
          for (arg = (uint *)arg_list[1]; arg != (uint *)0x0; arg = (uint *)*arg) {
            eh_merge_state_markers((c1_node *)arg[1]);
          }
        }
      }
      node = node->left;
      if (node == (c1_node *)0x0) {
        return;
      }
    }
    eh_merge_state_markers(node->left);
    eh_merge_state_markers(node->right);
    if (node->op == '7') {
      pcVar8 = node->left;
      cVar1 = *pcVar8;
      if ((((cVar1 == -0x3d) || (cVar1 == -0x3e)) && (pcVar3 = node->right, cVar1 == *pcVar3)) &&
         ((g_eh_state_table[*(int *)(pcVar8 + 0x10)].kind ==
           g_eh_state_table[*(int *)(pcVar3 + 0x10)].kind &&
          (*(short *)(pcVar8 + 0x16) == *(short *)(pcVar3 + 0x16))))) {
        pcVar9 = node;
        for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
          cVar1 = pcVar8[1];
          cVar4 = pcVar8[2];
          cVar5 = pcVar8[3];
          pcVar9->op = pcVar8[0];
          pcVar9->kind = cVar1;
          pcVar9->flags = cVar4;
          pcVar9->pad03 = cVar5;
          pcVar8 = pcVar8 + 4;
          pcVar9 = (c1_node *)&pcVar9->type;
        }
        uVar2 = *(ushort *)&node->right;
        *(ushort *)&node->right = (*(short *)(pcVar3 + 0x14) + uVar2 ^ uVar2) & 0xfff ^ uVar2;
      }
    }
  }
  return;
}

