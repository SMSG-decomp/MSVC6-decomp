int __cdecl init_split_address_constant(c1_node *node,void **symbol,int *offset)

{
  byte bVar1;
  void *pvVar2;
  byte *pbVar3;
  uint uVar4;
  c1_node *pcVar5;
  int iVar6;
  
  pcVar5 = tree_strip_casts_and_segment_bases(node);
  bVar1 = pcVar5->kind;
  while (uVar4 = (bVar1 & 7) - 2, uVar4 < 4) {
    switch((&switchD_10621829::switchdataD_106218e0)[uVar4]) {
    case (undefined *)0x106218b6:
      *offset = *offset + (int)pcVar5->left;
      return 1;
    case (undefined *)0x106218c8:
      *symbol = pcVar5->left;
      return 1;
    case (undefined *)0x1063b10d:
      pcVar5 = expr_string_literal(pcVar5);
      iVar6 = init_split_address_constant_fragment_2(pcVar5,symbol);
      return iVar6;
    }
    switch(pcVar5->op) {
    default:
      goto init_split_address_constant_fragment_3;
    case 'Q':
      if ((*(byte *)((int)pcVar5->left + 1) & 7) == 3) {
        pvVar2 = pcVar5->right;
        pcVar5->right = pcVar5->left;
        pcVar5->left = pvVar2;
      }
    case 'A':
    case 'F':
    case 'P':
    case 'S':
      pvVar2 = pcVar5->right;
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
      iVar6 = *(int *)((int)pvVar2 + 0x10);
      if (pcVar5->op == 'F') {
        iVar6 = -iVar6;
      }
      *offset = *offset + iVar6;
      pcVar5 = tree_strip_casts_and_segment_bases(pcVar5->left);
      bVar1 = pcVar5->kind;
    }
  }
init_split_address_constant_fragment_3:
  return 0;
}

