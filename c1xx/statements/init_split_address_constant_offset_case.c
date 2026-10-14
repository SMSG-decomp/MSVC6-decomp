int __cdecl init_split_address_constant_offset_case(c1_node *node,int *offset,int zero,void **base)

{
  byte bVar1;
  void *pvVar2;
  byte *pbVar3;
  void *pvVar4;
  c1_node *node_00;
  int iVar5;
  
code_r0x104424a9:
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
  iVar5 = *(int *)((int)pvVar2 + 0x10);
  if (node->op == 'F') {
    iVar5 = -iVar5;
  }
  *offset = *offset + iVar5;
  node = tree_strip_casts_and_segment_bases(node->left);
  switch(node->kind & 7) {
  case 2:
    break;
  case 3:
    *offset = *offset + (int)node->left;
    return 1;
  case 4:
    *base = node->left;
    return 1;
  case 5:
    node_00 = expr_string_literal(node);
    iVar5 = init_split_address_constant_case2_fragment(node_00,base);
    return iVar5;
  default:
    return 0;
  }
  switch(node->op) {
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
    break;
  case 0x9e:
    pvVar2 = node->left;
    pvVar4 = node->right;
    if ((((*(byte *)((int)pvVar2 + 1) & 7) == 3) &&
        (*(int *)((int)pvVar2 + 0x10) == 0 && *(int *)((int)pvVar2 + 0x14) == 0)) &&
       ((*(byte *)((int)pvVar4 + 1) & 7) == 3)) {
      pbVar3 = *(byte **)((int)pvVar4 + 4);
      bVar1 = *pbVar3;
      while ((char)bVar1 < '\0') {
        pbVar3 = *(byte **)(pbVar3 + 4);
        bVar1 = *pbVar3;
      }
      if ((*pbVar3 & 0x10) != 0) {
        *(int *)((int)pvVar4 + 0x10) = zero;
        *(int *)((int)pvVar4 + 0x14) = zero;
      }
    }
  }
  goto code_r0x104424a9;
}

