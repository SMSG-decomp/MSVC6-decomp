int __fastcall tree_reads_memory_through_temp(c2_node *n)

{
  uint32_t uVar1;
  c2_node *pcVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 1 << (n->kind & 0x1f);
  if ((uVar4 & 0xffe) == 0) {
    for (pcVar2 = *(c2_node **)&n[1].kind; pcVar2 != (c2_node *)0x0; pcVar2 = pcVar2->next) {
      iVar3 = tree_reads_memory_through_temp(pcVar2);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  else {
    if (((uVar4 & 6) != 0) && (pcVar2 = *(c2_node **)(n[1].op + 0x14), pcVar2 != (c2_node *)0x0)) {
      iVar3 = tree_has_side_effect_or_mem_read(pcVar2);
      return iVar3;
    }
    if (((n->kind == 6) &&
        ((iVar3 = *(int *)&n[2].kind, iVar3 == 0 ||
         (((1 << (*(byte *)(iVar3 + 8) & 0x1f) & 6U) != 0 &&
          (*(int *)(*(int *)(iVar3 + 0x14) + 0x14) != 0)))))) &&
       ((uVar1 = n[2].rank_or_prev, uVar1 == 0 ||
        (((1 << (*(byte *)(uVar1 + 8) & 0x1f) & 6U) != 0 &&
         (*(int *)(*(int *)(uVar1 + 0x14) + 0x14) != 0)))))) {
      pcVar2 = *(c2_node **)(*(int *)(iVar3 + 0x14) + 0x14);
      iVar3 = node_has_side_effects(pcVar2);
      if (iVar3 == 0) {
        iVar3 = tree_reads_memory_through_temp(pcVar2);
        return iVar3;
      }
      return 1;
    }
  }
  return 0;
}

