c1_symbol * __cdecl expr_find_base_symbol(c1_node *node)

{
  c1_u8 cVar1;
  c1_node *pcVar2;
  
  cVar1 = node->op;
  do {
    switch(cVar1) {
    case '\x06':
      return node->left;
    default:
      return (c1_symbol *)0x0;
    case '6':
      pcVar2 = node->right;
      if (node->type != pcVar2->type) goto switchD_10416be4_caseD_41;
      break;
    case 'A':
    case 'P':
    case ']':
switchD_10416be4_caseD_41:
      pcVar2 = node->left;
    }
    cVar1 = pcVar2->op;
    node = pcVar2;
  } while( true );
}

