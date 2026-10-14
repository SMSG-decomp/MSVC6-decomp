void __cdecl name_intern_keyword(byte *text)

{
  fe_name **ppfVar1;
  byte bVar2;
  byte *pbVar3;
  fe_name *pfVar4;
  fe_name *pfVar5;
  uchar *puVar6;
  uchar *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  
  pbVar12 = text;
  pbVar8 = (byte *)0x0;
  bVar2 = *text;
  pbVar3 = text;
  while (pbVar3 = pbVar3 + 1, bVar2 != 0) {
    text = (byte *)(uint)bVar2;
    pbVar8 = text + ((uint)pbVar8 >> 4) + (int)pbVar8 * 4;
    bVar2 = *pbVar3;
  }
  pbVar9 = pbVar3 + (-1 - (int)pbVar12);
  ppfVar1 = g_name_hash + ((uint)pbVar8 & 0x7ff);
  uVar11 = (uint)pbVar8 >> 0x10 ^ (uint)pbVar8 & 0xffff;
  pfVar4 = (fe_name *)ppfVar1;
  pfVar5 = *ppfVar1;
  do {
    if (pfVar5 == (fe_name *)0x0) {
      if (g_name_pool.left < 0x14) {
        pool_reserve(&g_name_pool,0x14);
      }
      puVar6 = g_name_pool.cur;
      g_name_pool.left = g_name_pool.left - 0x14;
      puVar7 = g_name_pool.cur + 0x14;
      *(fe_name **)g_name_pool.cur = *ppfVar1;
      g_name_pool.cur = puVar7;
      *ppfVar1 = (fe_name *)puVar6;
      pbVar8 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + ((uint)(pbVar3 + (3 - (int)pbVar12)) & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(byte **)(puVar6 + 4) = pbVar8;
      for (uVar10 = (uint)pbVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pbVar8 = *(undefined4 *)pbVar12;
        pbVar12 = pbVar12 + 4;
        pbVar8 = pbVar8 + 4;
      }
      for (uVar10 = (uint)pbVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pbVar8 = *pbVar12;
        pbVar12 = pbVar12 + 1;
        pbVar8 = pbVar8 + 1;
      }
      pbVar9[*(int *)(puVar6 + 4)] = 0;
      g_last_name = (fe_name *)puVar6;
      *(uint *)(puVar6 + 8) = (*(uint *)(puVar6 + 8) ^ uVar11) & 0xffff ^ *(uint *)(puVar6 + 8);
      return;
    }
    if (((pfVar5->flags & 0xffff) == uVar11) && (pfVar5->text[(int)pbVar9] == 0)) {
      bVar15 = true;
      pbVar8 = pbVar9;
      pbVar13 = pbVar12;
      pbVar14 = (byte *)pfVar5->text;
      do {
        if (pbVar8 == (byte *)0x0) break;
        pbVar8 = pbVar8 + -1;
        bVar15 = *pbVar13 == *pbVar14;
        pbVar13 = pbVar13 + 1;
        pbVar14 = pbVar14 + 1;
      } while (bVar15);
      if (bVar15) {
        pfVar4->next = pfVar5->next;
        pfVar5->next = *ppfVar1;
        *ppfVar1 = pfVar5;
        g_last_name = pfVar5;
        return;
      }
    }
    pfVar4 = pfVar5;
    pfVar5 = pfVar5->next;
  } while( true );
}

