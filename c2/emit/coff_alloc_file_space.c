uint32_t __fastcall coff_alloc_file_space(uint32_t size,uint32_t wanted)

{
  c2_coff_free_range *pcVar1;
  c2_coff_free_range *pcVar2;
  uint32_t uVar3;
  c2_coff_free_range *pcVar4;
  c2_coff_free_range **ppcVar5;
  int iVar6;
  
  if ((wanted != 0) &&
     (ppcVar5 = &g_coff_free_ranges, pcVar1 = g_coff_free_ranges,
     g_coff_free_ranges != (c2_coff_free_range *)0x0)) {
    while (pcVar4 = pcVar1, pcVar4->start != wanted) {
      if ((wanted <= pcVar4->start) ||
         (pcVar1 = pcVar4->next, ppcVar5 = &pcVar4->next, pcVar4->next == (c2_coff_free_range *)0x0)
         ) goto LAB_107829eb;
    }
    pcVar1 = ((c2_coff_free_range *)ppcVar5)->next;
    if (size <= (uint)pcVar1->size) {
      iVar6 = pcVar1->size - size;
      pcVar1->size = iVar6;
      if (iVar6 != 0) {
        pcVar1->start = pcVar1->start + size;
        return wanted;
      }
      ((c2_coff_free_range *)ppcVar5)->next = pcVar1->next;
      return wanted;
    }
  }
LAB_107829eb:
  pcVar1 = g_coff_free_ranges;
  pcVar4 = (c2_coff_free_range *)&g_coff_free_ranges;
  if (g_coff_free_ranges == (c2_coff_free_range *)0x0) {
    uVar3 = g_coff_data_end;
    g_coff_data_end = g_coff_data_end + size;
    return uVar3;
  }
  do {
    pcVar2 = pcVar1;
    if (size <= (uint)pcVar2->size) {
      pcVar1 = pcVar4->next;
      uVar3 = pcVar1->start;
      iVar6 = pcVar1->size - size;
      pcVar1->size = iVar6;
      if (iVar6 != 0) {
        pcVar1->start = pcVar1->start + size;
        return uVar3;
      }
      pcVar4->next = pcVar1->next;
      return uVar3;
    }
    pcVar1 = pcVar2->next;
    pcVar4 = pcVar2;
  } while (pcVar2->next != (c2_coff_free_range *)0x0);
  uVar3 = g_coff_data_end;
  g_coff_data_end = g_coff_data_end + size;
  return uVar3;
}

