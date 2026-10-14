char __cdecl pdb_gi_read_blob_for_pch(void)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x3004;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(uchar *)((int)puVar5 + 0) = '\0';
  *(uchar *)((int)puVar5 + 1) = '0';
  *(uchar *)((int)puVar5 + 2) = '\0';
  *(uchar *)((int)puVar5 + 3) = '\0';
  iVar2 = (*g_pdb_gi->mre_driver->vtbl->store_pch_deps)(g_pdb_gi->mre_driver,puVar5);
  puVar1 = g_arenas[0].cur;
  if (iVar2 == 0) {
    uVar4 = *puVar5;
    if (uVar4 != 0) {
      if (0x3000 < uVar4) {
        g_arenas[0].cur = g_arenas[0].cur + (uVar4 + 7 & 0xfffffffc);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        g_pdb_gi_pch_blob = (uint *)puVar1;
        *(uint *)puVar1 = *puVar5;
        (*g_pdb_gi->mre_driver->vtbl->store_pch_deps)(g_pdb_gi->mre_driver,g_pdb_gi_pch_blob);
        return '\x01';
      }
      return '\0';
    }
  }
  else {
    g_arenas[0].cur = g_arenas[0].cur + (*puVar5 + 7 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    g_pdb_gi_pch_blob = (uint *)puVar1;
    *(uint *)puVar1 = *puVar5;
    uVar4 = *g_pdb_gi_pch_blob;
    uVar3 = uVar4 >> 2;
    puVar6 = g_pdb_gi_pch_blob;
    while( true ) {
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      *puVar6 = *puVar5;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)puVar6 = (char)*puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      puVar6 = (uint *)((int)puVar6 + 1);
    }
  }
  return '\x01';
}

