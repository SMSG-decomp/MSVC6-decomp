c1_node * __cdecl expr_find_lvalue_symbol_node(c1_node *node)

{
  c1_node *pcVar1;
  uint uVar2;
  
  uVar2 = node->op - 6;
  if (uVar2 < 0x71) {
    do {
      switch((&switchD_10416eef::switchdataD_10416f98)[uVar2]) {
      case 6:
      case 100:
        return node;
      default:
        goto switchD_10416eef_caseD_6;
      case 0x36:
        pcVar1 = node->right;
        if (node->type != pcVar1->type) goto switchD_10416eef_caseD_41;
        goto LAB_10416ef9;
      case 0x53:
        return node->left;
      case 0x5d:
        pcVar1 = node->left;
        node = pcVar1;
        if (pcVar1->op != '=') goto LAB_10416ef9;
      case 0x41:
      case 0x50:
      case 0x76:
switchD_10416eef_caseD_41:
        pcVar1 = node->left;
LAB_10416ef9:
        uVar2 = pcVar1->op - 6;
        node = pcVar1;
        if (0x70 < uVar2) {
          return (c1_node *)0x0;
        }
      }
    } while( true );
  }
switchD_10416eef_caseD_6:
  return (c1_node *)0x0;
}

