int __cdecl init_split_address_constant_fragment(c1_u8 op,c1_node *node,int *offset,void **symbol)

{
  byte bVar1;
  void *pvVar2;
  byte *pbVar3;
  c1_node *node_00;
  int iVar4;
  
  do {
    pvVar2 = node->right;
    if ((*(byte *)((int)pvVar2 + 1) & 7) != 3) {
      return 0;
    }
    pbVar3 = *(byte **)((int)pvVar2 + 4);
    bVar1 = *pbVar3;
    while ((char)bVar1 < '\0') {
      pbVar3 = *(byte **)(pbVar3 + 4);
      bVar1 = *pbVar3;
    }
    if ((*pbVar3 & 0x10) == 0) {
      return 0;
    }
    iVar4 = *(int *)((int)pvVar2 + 0x10);
    if (op == 'F') {
      iVar4 = -iVar4;
    }
    *offset = *offset + iVar4;
    node = tree_strip_casts_and_segment_bases(node->left);
    switch(node->kind & 7) {
    case 2:
      op = node->op;
      switch(op) {
      default:
        return 0;
      case 'A':
      case 'F':
      case 'P':
      case 'S':
        break;
      case 'Q':
        if ((*(byte *)((int)node->left + 1) & 7) == 3) {
          pvVar2 = node->right;
          node->right = node->left;
          node->left = pvVar2;
        }
      }
      break;
    case 3:
      *offset = *offset + (int)node->left;
      return 1;
    case 4:
      *symbol = node->left;
      return 1;
    case 5:
      node_00 = expr_string_literal(node);
      iVar4 = init_split_address_constant_fragment_2(node_00,symbol);
      return iVar4;
    default:
      return 0;
    }
  } while( true );
}

