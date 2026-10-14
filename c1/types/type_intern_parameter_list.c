c1_param_list * __cdecl type_intern_parameter_list(c1_param_list *list)

{
  c1_param_list_entry *pcVar1;
  c1_param_list_entry *pcVar2;
  uchar *puVar3;
  c1_param_list_entry *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  c1_type **ppcVar9;
  c1_type **ppcVar10;
  c1_param_list *pcVar11;
  bool bVar12;
  bool bVar13;
  c1_param_list_entry *local_8;
  
  uVar5 = type_param_list_hash(&list->count);
  puVar3 = g_arenas[0].cur;
  iVar8 = list->count;
  pcVar1 = (c1_param_list_entry *)(g_param_list_hash + (uVar5 & 0x3ff));
  local_8 = (c1_param_list_entry *)0x0;
  pcVar4 = g_param_list_hash[uVar5 & 0x3ff];
  while (pcVar2 = pcVar4, pcVar2 != (c1_param_list_entry *)0x0) {
    iVar7 = (pcVar2->list).count;
    if (iVar8 <= iVar7) {
      if (iVar8 < iVar7) break;
      iVar7 = iVar8 * 4;
      bVar12 = false;
      iVar6 = 0;
      bVar13 = true;
      ppcVar9 = (pcVar2->list).types;
      ppcVar10 = list->types;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar12 = *(byte *)ppcVar9 < *(byte *)ppcVar10;
        bVar13 = *(byte *)ppcVar9 == *(byte *)ppcVar10;
        ppcVar9 = (c1_type **)((int)ppcVar9 + 1);
        ppcVar10 = (c1_type **)((int)ppcVar10 + 1);
      } while (bVar13);
      if (!bVar13) {
        iVar6 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      }
      if (iVar6 == 0) {
        return &pcVar2->list;
      }
    }
    local_8 = pcVar2;
    pcVar4 = pcVar2->next;
  }
  g_arenas[0].cur = g_arenas[0].cur + iVar8 * 4 + 0xc;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_param_list_entry **)puVar3 = pcVar2;
  if (local_8 == (c1_param_list_entry *)0x0) {
    local_8 = pcVar1;
  }
  local_8->next = (c1_param_list_entry *)puVar3;
  pcVar11 = (c1_param_list *)(puVar3 + 4);
  for (uVar5 = iVar8 * 4 + 8U >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    pcVar11->count = list->count;
    list = (c1_param_list *)&list->debug_index;
    pcVar11 = (c1_param_list *)&pcVar11->debug_index;
  }
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(uchar *)&pcVar11->count = (uchar)list->count;
    list = (c1_param_list *)((int)&list->count + 1);
    pcVar11 = (c1_param_list *)((int)&pcVar11->count + 1);
  }
  return (c1_param_list *)(puVar3 + 4);
}

