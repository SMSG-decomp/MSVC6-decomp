int __cdecl pdb_gi_read_blob_for_pch(void)

{
  c1_u8 *pcVar1;
  int iVar2;
  uint uVar3;
  uint result;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x3004;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *(c1_u8 *)((int)puVar5 + 0) = '\0';
  *(c1_u8 *)((int)puVar5 + 1) = '0';
  *(c1_u8 *)((int)puVar5 + 2) = '\0';
  *(c1_u8 *)((int)puVar5 + 3) = '\0';
  iVar2 = (*g_pdb_gi->mre_compiler->vtbl->save_state)(puVar5);
  pcVar1 = g_arenas[0].cur;
  if (iVar2 == 0) {
    uVar4 = *puVar5;
    uVar3 = 0;
    if (uVar4 != 0) {
      if (0x3000 < uVar4) {
        g_arenas[0].cur = g_arenas[0].cur + (uVar4 + 7 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        g_pdb_gi_pch_blob = (uint *)pcVar1;
        *(uint *)pcVar1 = *puVar5;
        result = (*g_pdb_gi->mre_compiler->vtbl->save_state)(g_pdb_gi_pch_blob);
        return CONCAT31((int3)(result >> 8),1);
      }
      return 0;
    }
  }
  else {
    g_arenas[0].cur = g_arenas[0].cur + (*puVar5 + 7 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    g_pdb_gi_pch_blob = (uint *)pcVar1;
    *(uint *)pcVar1 = *puVar5;
    uVar3 = *g_pdb_gi_pch_blob;
    uVar4 = uVar3 >> 2;
    puVar6 = g_pdb_gi_pch_blob;
    while( true ) {
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      *puVar6 = *puVar5;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)puVar6 = (char)*puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      puVar6 = (uint *)((int)puVar6 + 1);
    }
  }
  return CONCAT31((int3)(uVar3 >> 8),1);
}

