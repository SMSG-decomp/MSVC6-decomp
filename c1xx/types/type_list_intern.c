c1_type_list * __cdecl type_list_intern(int *list,uint hash)

{
  c1_type_list *pcVar1;
  uint *puVar2;
  uint **ppuVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *cursor;
  c1_type_list *pcVar7;
  int *piVar8;
  bool bVar9;
  uint **bucket;
  uint **entry;
  
  uVar4 = hash & 0x1ff;
  iVar5 = *list;
  bucket = g_type_list_hash + uVar4;
  hash = 0;
  ppuVar3 = (uint **)g_type_list_hash[uVar4];
  while (entry = ppuVar3, entry != (uint **)0x0) {
    if (iVar5 <= (int)entry[1]) {
      if (iVar5 < (int)entry[1]) break;
      iVar6 = iVar5 * 4;
      bVar9 = true;
      cursor = (uint *)(entry + 3);
      piVar8 = list + 2;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar9 = (char)*cursor == (char)*piVar8;
        cursor = (uint *)((int)cursor + 1);
        piVar8 = (int *)((int)piVar8 + 1);
      } while (bVar9);
      if (bVar9) {
        return (c1_type_list *)(entry + 1);
      }
    }
    hash = (uint)entry;
    ppuVar3 = (uint **)*entry;
  }
  uVar4 = iVar5 * 4 + 0xc;
  if (g_type_list_pool_left < uVar4) {
    pool_reserve((c1xx_pool *)&g_type_list_pool,uVar4);
  }
  puVar2 = g_type_list_pool;
  g_type_list_pool_left = g_type_list_pool_left - uVar4;
  pcVar1 = (c1_type_list *)(g_type_list_pool + 1);
  pcVar7 = pcVar1;
  g_type_list_pool = g_type_list_pool + iVar5 + 3;
  for (uVar4 = iVar5 * 4 + 8U >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar7->count = *list;
    list = list + 1;
    pcVar7 = (c1_type_list *)&pcVar7->unk04;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(char *)&pcVar7->count = (char)*list;
    list = (int *)((int)list + 1);
    pcVar7 = (c1_type_list *)((int)&pcVar7->count + 1);
  }
  *puVar2 = (uint)entry;
  if ((uint **)hash == (uint **)0x0) {
    hash = (uint)bucket;
  }
  *(uint **)hash = puVar2;
  return pcVar1;
}

