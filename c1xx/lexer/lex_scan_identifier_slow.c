uint __cdecl lex_scan_identifier_slow(c1_u8 *start,uint hash,byte c)

{
  fe_name *pfVar1;
  fe_name *pfVar2;
  fe_name *pfVar3;
  uchar *puVar4;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  c1_u8 *pcVar11;
  c1_u8 *pcVar12;
  bool bVar13;
  uint local_808;
  uchar *bucket;
  c1_u8 local_800 [2048];
  uchar *new_rec;
  
  bVar7 = c;
  _c = (uint)c;
  pbVar5 = g_input_ptr + (-1 - (int)start);
  local_808 = 0;
  pcVar11 = local_800;
  for (uVar8 = (uint)pbVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)start;
    start = start + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar8 = (uint)pbVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar11 = *start;
    start = start + 1;
    pcVar11 = pcVar11 + 1;
  }
  pbVar5 = local_800 + (int)pbVar5;
  do {
    if (bVar7 == 0) {
      if (0 < g_macro_expansion_depth) {
LAB_1040ac14:
        g_input_ptr = g_input_ptr + -1;
        uVar10 = (int)pbVar5 - (int)local_800;
        pfVar1 = (fe_name *)(g_name_hash + (hash & 0x7ff));
        uVar8 = hash >> 0x10 ^ hash & 0xffff;
        pfVar2 = pfVar1;
        pfVar3 = pfVar1->next;
        break;
      }
      iVar6 = file_read_or_fatal();
      if (iVar6 != 0) {
        iVar6 = 4;
        goto LAB_1045bd22;
      }
    }
    else if (g_char_class[_c] == ')') {
      bVar7 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      local_808 = (uint)bVar7;
    }
    else {
      if (bVar7 == 0x3f) {
        uVar8 = lex_trigraph();
        uVar8 = uVar8 & 0xffffffbf;
      }
      else {
        if (bVar7 != 0x5c) goto LAB_1040ac14;
        uVar8 = lex_line_splice();
      }
      if (uVar8 == 0) goto LAB_1040ac14;
    }
    bVar7 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (&stack0x00000000 <= pbVar5) {
      iVar6 = 0x40;
LAB_1045bd22:
      diag_fatal_simple(iVar6);
    }
    while (_c = (uint)bVar7, (g_char_flags[_c] & 3) != 0) {
      *pbVar5 = bVar7;
      bVar7 = *g_input_ptr;
      pbVar5 = pbVar5 + 1;
      g_input_ptr = g_input_ptr + 1;
      hash = _c + (hash >> 4) + hash * 4;
      if (&stack0x00000000 <= pbVar5) {
        uVar8 = lex_scan_identifier_slow_overflow();
        return uVar8;
      }
    }
    if (&stack0x00000000 <= pbVar5) {
      uVar8 = lex_scan_identifier_slow_overflow();
      return uVar8;
    }
  } while( true );
joined_r0x1040ac54:
  if (pfVar3 == (fe_name *)0x0) {
    bucket = (uchar *)pfVar1;
    if (g_name_pool_left < 0x10) {
      pool_reserve((c1xx_pool *)&g_name_pool,0x10);
    }
    new_rec = g_name_pool;
    g_name_pool_left = g_name_pool_left - 0x10;
    puVar4 = g_name_pool + 0x10;
    *(fe_name **)g_name_pool = pfVar1->next;
    g_name_pool = puVar4;
    pfVar1->next = (fe_name *)new_rec;
    pcVar11 = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + (uVar10 + 4 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_u8 **)(new_rec + 4) = pcVar11;
    pcVar12 = local_800;
    for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar9 = uVar10 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar11 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar11 = pcVar11 + 1;
    }
    *(undefined1 *)(*(int *)(new_rec + 4) + uVar10) = 0;
    g_last_name = (fe_name *)new_rec;
    *(uint *)(new_rec + 8) = (*(uint *)(new_rec + 8) ^ uVar8) & 0xffff ^ *(uint *)(new_rec + 8);
LAB_1040ac9b:
    return (uint)(local_808 == uVar10);
  }
  if (((pfVar3->flags & 0xffff) == uVar8) && (pfVar3->text[uVar10] == '\0')) {
    bVar13 = true;
    uVar9 = uVar10;
    pcVar11 = local_800;
    pcVar12 = (c1_u8 *)pfVar3->text;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      bVar13 = *pcVar11 == *pcVar12;
      pcVar11 = pcVar11 + 1;
      pcVar12 = pcVar12 + 1;
    } while (bVar13);
    if (bVar13) {
      pfVar2->next = pfVar3->next;
      pfVar3->next = pfVar1->next;
      pfVar1->next = pfVar3;
      g_last_name = pfVar3;
      goto LAB_1040ac9b;
    }
  }
  pfVar2 = pfVar3;
  pfVar3 = pfVar3->next;
  goto joined_r0x1040ac54;
}

