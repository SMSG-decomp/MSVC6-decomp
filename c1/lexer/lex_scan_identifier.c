int __cdecl lex_scan_identifier(byte first)

{
  fe_name **ppfVar1;
  byte bVar2;
  fe_name *pfVar3;
  fe_name *pfVar4;
  uchar *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *start;
  byte *pbVar10;
  bool bVar11;
  uchar *rec;
  
  uVar6 = (uint)first;
  uVar8 = 0;
  start = g_input_ptr + -1;
  bVar2 = g_char_flags[uVar6];
  while ((bVar2 & 3) != 0) {
    uVar8 = uVar6 + (uVar8 >> 4) + uVar8 * 4;
    first = *g_input_ptr;
    uVar6 = (uint)first;
    g_input_ptr = g_input_ptr + 1;
    bVar2 = g_char_flags[uVar6];
  }
  if ((g_char_class[first] == '\0') || ((first == 4 && (0 < g_macro_expansion_depth)))) {
    uVar8 = lex_scan_identifier_slow(start,uVar8,first);
    return uVar8;
  }
  g_input_ptr = g_input_ptr + -1;
  uVar6 = (int)g_input_ptr - (int)start;
  if (0x7ff < (int)uVar6) {
    diag_fatal_simple(0x40);
  }
  ppfVar1 = g_name_hash + (uVar8 & 0x7ff);
  uVar8 = uVar8 >> 0x10 ^ uVar8 & 0xffff;
  pfVar3 = (fe_name *)ppfVar1;
  pfVar4 = *ppfVar1;
  do {
    if (pfVar4 == (fe_name *)0x0) {
      if (g_name_pool.left < 0x10) {
        pool_reserve(&g_name_pool,0x10);
      }
      rec = g_name_pool.cur;
      g_name_pool.left = g_name_pool.left - 0x10;
      puVar5 = g_name_pool.cur + 0x10;
      *(fe_name **)g_name_pool.cur = *ppfVar1;
      g_name_pool.cur = puVar5;
      *ppfVar1 = (fe_name *)rec;
      pbVar9 = g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + (uVar6 + 4 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(byte **)(rec + 4) = pbVar9;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pbVar9 = *(undefined4 *)start;
        start = start + 4;
        pbVar9 = pbVar9 + 4;
      }
      for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pbVar9 = *start;
        start = start + 1;
        pbVar9 = pbVar9 + 1;
      }
      *(undefined1 *)(*(int *)(rec + 4) + uVar6) = 0;
      g_last_name = (fe_name *)rec;
      *(uint *)(rec + 8) = (*(uint *)(rec + 8) ^ uVar8) & 0xffff ^ *(uint *)(rec + 8);
      return 0;
    }
    if (((pfVar4->flags & 0xffff) == uVar8) && (pfVar4->text[uVar6] == 0)) {
      bVar11 = true;
      uVar7 = uVar6;
      pbVar9 = start;
      pbVar10 = (byte *)pfVar4->text;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar11 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + 1;
        pbVar10 = pbVar10 + 1;
      } while (bVar11);
      if (bVar11) {
        pfVar3->next = pfVar4->next;
        pfVar4->next = *ppfVar1;
        *ppfVar1 = pfVar4;
        g_last_name = pfVar4;
        return 0;
      }
    }
    pfVar3 = pfVar4;
    pfVar4 = pfVar4->next;
  } while( true );
}

