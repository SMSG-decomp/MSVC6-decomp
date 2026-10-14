int __cdecl expr_find_based_base(c1_node *node)

{
  int iVar1;
  int iVar2;
  
  while (node != (c1_node *)0x0) {
    switch(node->op) {
    case '4':
    case '7':
    case 'V':
      node = node->right;
      break;
    default:
      goto switchD_104690bc_caseD_35;
    case '6':
      iVar1 = expr_find_based_base(node->left);
      iVar2 = expr_find_based_base(node->right);
      if (iVar1 != 0) {
        iVar2 = iVar1;
      }
      return iVar2;
    case ']':
      return (int)node->right;
    }
  }
switchD_104690bc_caseD_35:
  return 0;
}

