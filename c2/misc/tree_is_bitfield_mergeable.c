int __fastcall tree_is_bitfield_mergeable(c2_node *n)

{
  byte bVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  c2_node *pcVar7;
  
  bVar1 = n->kind;
  while (uVar5 = 1 << (bVar1 & 0x1f), (uVar5 & 0xffe) != 0) {
    if (((uVar5 & 6) == 0) || (pcVar7 = *(c2_node **)(n[1].op + 0x14), pcVar7 == (c2_node *)0x0)) {
      if ((uVar5 & 0x60) == 0) {
        return 1;
      }
      uVar2 = *(uint32_t *)&n[2].kind;
      if (uVar2 != 0) {
        if ((1 << (*(byte *)(uVar2 + 8) & 0x1f) & 6U) == 0) {
          return 1;
        }
        if (*(int *)(*(int *)(uVar2 + 0x14) + 0x14) == 0) {
          return 1;
        }
      }
      uVar3 = n[2].rank_or_prev;
      if (uVar3 != 0) {
        if ((1 << (*(byte *)(uVar3 + 8) & 0x1f) & 6U) == 0) {
          return 1;
        }
        if (*(int *)(*(int *)(uVar3 + 0x14) + 0x14) == 0) {
          return 1;
        }
      }
      if (uVar2 == uVar3) {
        return 1;
      }
      pcVar7 = *(c2_node **)(*(int *)(uVar2 + 0x14) + 0x14);
    }
    n = pcVar7;
    bVar1 = pcVar7->kind;
  }
  if (*(char *)((int)&n[1].next + 2) != '\x02') {
    return 0;
  }
  uVar2 = n[1].rank_or_prev;
  if (((((1 << (*(byte *)(uVar2 + 8) & 0x1f) & 0x60U) != 0) &&
       ((iVar6 = *(int *)(uVar2 + 0x28), iVar6 == 0 ||
        (((1 << (*(byte *)(iVar6 + 8) & 0x1f) & 6U) != 0 &&
         (*(int *)(*(int *)(iVar6 + 0x14) + 0x14) != 0)))))) &&
      ((iVar4 = *(int *)(uVar2 + 0x2c), iVar4 == 0 ||
       (((1 << (*(byte *)(iVar4 + 8) & 0x1f) & 6U) != 0 &&
        (*(int *)(*(int *)(iVar4 + 0x14) + 0x14) != 0)))))) && (iVar6 != iVar4)) {
    return 0;
  }
  pcVar7 = *(c2_node **)&n[1].kind;
  while( true ) {
    if (pcVar7 == (c2_node *)0x0) {
      return 1;
    }
    iVar6 = tree_is_bitfield_mergeable(pcVar7);
    if (iVar6 == 0) break;
    pcVar7 = pcVar7->next;
  }
  return 0;
}

