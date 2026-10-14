fe_name * __cdecl name_intern(char *s)

{
  fe_name **ppfVar1;
  byte bVar2;
  byte *pbVar3;
  fe_name *pfVar4;
  fe_name *pfVar5;
  uchar *puVar6;
  char *pcVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uchar *puVar12;
  uchar *puVar13;
  char *pcVar14;
  bool bVar15;
  
  puVar12 = (uchar *)s;
  pcVar7 = (char *)0x0;
  bVar2 = *s;
  pbVar3 = (byte *)s;
  while (pbVar3 = pbVar3 + 1, bVar2 != 0) {
    s = (char *)(uint)bVar2;
    pcVar7 = s + ((uint)pcVar7 >> 4) + (int)pcVar7 * 4;
    bVar2 = *pbVar3;
  }
  pbVar8 = pbVar3 + (-1 - (int)puVar12);
  ppfVar1 = g_name_hash + ((uint)pcVar7 & 0x7ff);
  uVar11 = (uint)pcVar7 >> 0x10 ^ (uint)pcVar7 & 0xffff;
  pfVar4 = (fe_name *)ppfVar1;
  pfVar5 = *ppfVar1;
  do {
    if (pfVar5 == (fe_name *)0x0) {
      if (g_name_pool.left < 0x10) {
        pool_reserve(&g_name_pool,0x10);
      }
      puVar6 = g_name_pool.cur;
      g_name_pool.left = g_name_pool.left - 0x10;
      puVar13 = g_name_pool.cur + 0x10;
      *(fe_name **)g_name_pool.cur = *ppfVar1;
      g_name_pool.cur = puVar13;
      *ppfVar1 = (fe_name *)puVar6;
      puVar13 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + ((uint)(pbVar3 + (3 - (int)puVar12)) & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(uchar **)(puVar6 + 4) = puVar13;
      for (uVar9 = (uint)pbVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)puVar13 = *(undefined4 *)puVar12;
        puVar12 = puVar12 + 4;
        puVar13 = puVar13 + 4;
      }
      for (uVar9 = (uint)pbVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar13 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
      pbVar8[*(int *)(puVar6 + 4)] = 0;
      g_last_name = (fe_name *)puVar6;
      *(uint *)(puVar6 + 8) = (*(uint *)(puVar6 + 8) ^ uVar11) & 0xffff ^ *(uint *)(puVar6 + 8);
      return g_last_name;
    }
    if (((pfVar5->flags & 0xffff) == uVar11) && (pfVar5->text[(int)pbVar8] == '\0')) {
      bVar15 = true;
      pbVar10 = pbVar8;
      pcVar7 = (char *)puVar12;
      pcVar14 = pfVar5->text;
      do {
        if (pbVar10 == (byte *)0x0) break;
        pbVar10 = pbVar10 + -1;
        bVar15 = *pcVar7 == *pcVar14;
        pcVar7 = pcVar7 + 1;
        pcVar14 = pcVar14 + 1;
      } while (bVar15);
      if (bVar15) {
        pfVar4->next = pfVar5->next;
        pfVar5->next = *ppfVar1;
        *ppfVar1 = pfVar5;
        g_last_name = pfVar5;
        return pfVar5;
      }
    }
    pfVar4 = pfVar5;
    pfVar5 = pfVar5->next;
  } while( true );
}

