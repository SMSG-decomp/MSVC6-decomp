uint __cdecl lex_scan_identifier_slow(c1_u8 *start,uint hash,byte c)

{
  fe_name *pfVar1;
  fe_name *pfVar2;
  fe_name *pfVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  c1_u8 *pcVar10;
  uchar *puVar11;
  c1_u8 *pcVar12;
  uchar *puVar13;
  bool bVar14;
  uint local_808;
  fe_name *bucket;
  c1_u8 local_800 [2048];
  uchar *rec;
  
  bVar6 = c;
  _c = (uint)c;
  pbVar4 = g_input_ptr + (-1 - (int)start);
  local_808 = 0;
  pcVar10 = local_800;
  for (uVar7 = (uint)pbVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)start;
    start = start + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar7 = (uint)pbVar4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar10 = *start;
    start = start + 1;
    pcVar10 = pcVar10 + 1;
  }
  pbVar4 = local_800 + (int)pbVar4;
  do {
    if (bVar6 == 0) {
      if (0 < g_macro_expansion_depth) {
LAB_10607425:
        g_input_ptr = g_input_ptr + -1;
        uVar9 = (int)pbVar4 - (int)local_800;
        pfVar1 = (fe_name *)(g_name_hash + (hash & 0x7ff));
        uVar7 = hash >> 0x10 ^ hash & 0xffff;
        pfVar2 = pfVar1;
        pfVar3 = pfVar1->next;
        break;
      }
      iVar5 = file_read_or_fatal();
      if (iVar5 != 0) {
        uVar7 = lex_report_unexpected_eof_2();
        return uVar7;
      }
    }
    else if (g_char_class[_c] == ')') {
      bVar6 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      local_808 = (uint)bVar6;
    }
    else {
      if (bVar6 == 0x3f) {
        uVar7 = lex_trigraph();
        uVar7 = uVar7 & 0xffffffbf;
      }
      else {
        if (bVar6 != 0x5c) goto LAB_10607425;
        uVar7 = lex_line_splice();
      }
      if (uVar7 == 0) goto LAB_10607425;
    }
    bVar6 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (&stack0x00000000 <= pbVar4) {
      diag_fatal_simple(0x40);
    }
    while (_c = (uint)bVar6, (g_char_flags[_c] & 3) != 0) {
      *pbVar4 = bVar6;
      bVar6 = *g_input_ptr;
      pbVar4 = pbVar4 + 1;
      g_input_ptr = g_input_ptr + 1;
      hash = _c + (hash >> 4) + hash * 4;
      if (&stack0x00000000 <= pbVar4) {
        uVar7 = lex_scan_identifier_slow_overflow();
        return uVar7;
      }
    }
    if (&stack0x00000000 <= pbVar4) {
      uVar7 = lex_scan_identifier_slow_overflow();
      return uVar7;
    }
  } while( true );
joined_r0x10607465:
  if (pfVar3 == (fe_name *)0x0) {
    bucket = pfVar1;
    if (g_name_pool.left < 0x10) {
      pool_reserve(&g_name_pool,0x10);
    }
    rec = g_name_pool.cur;
    g_name_pool.left = g_name_pool.left - 0x10;
    puVar13 = g_name_pool.cur + 0x10;
    *(fe_name **)g_name_pool.cur = pfVar1->next;
    g_name_pool.cur = puVar13;
    pfVar1->next = (fe_name *)rec;
    puVar13 = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + (uVar9 + 4 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(uchar **)(rec + 4) = puVar13;
    puVar11 = local_800;
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)puVar13 = *(undefined4 *)puVar11;
      puVar11 = puVar11 + 4;
      puVar13 = puVar13 + 4;
    }
    for (uVar8 = uVar9 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar13 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
    }
    *(undefined1 *)(*(int *)(rec + 4) + uVar9) = 0;
    g_last_name = (fe_name *)rec;
    *(uint *)(rec + 8) = (*(uint *)(rec + 8) ^ uVar7) & 0xffff ^ *(uint *)(rec + 8);
LAB_106074ac:
    return (uint)(local_808 == uVar9);
  }
  if (((pfVar3->flags & 0xffff) == uVar7) && (pfVar3->text[uVar9] == '\0')) {
    bVar14 = true;
    uVar8 = uVar9;
    pcVar10 = local_800;
    pcVar12 = (c1_u8 *)pfVar3->text;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      bVar14 = *pcVar10 == *pcVar12;
      pcVar10 = pcVar10 + 1;
      pcVar12 = pcVar12 + 1;
    } while (bVar14);
    if (bVar14) {
      pfVar2->next = pfVar3->next;
      pfVar3->next = pfVar1->next;
      pfVar1->next = pfVar3;
      g_last_name = pfVar3;
      goto LAB_106074ac;
    }
  }
  pfVar2 = pfVar3;
  pfVar3 = pfVar3->next;
  goto joined_r0x10607465;
}

