c1_u8 * __cdecl lex_scan_character_constant(int wide,ushort *chars,ushort count)

{
  uchar *puVar1;
  ushort uVar2;
  fe_arena *a;
  uchar *puVar3;
  int iVar4;
  uint lo;
  uint uVar5;
  uint hi;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  short n;
  
  if (wide != 0) {
    lo = (uint)*chars;
    hi = 0;
    if (4 < count) {
      diag_warning(3,0x42);
    }
    g_yylval = (uint)g_type_unsigned_short;
    goto LAB_1062034a;
  }
  if (count == 0) {
    n = 0x89;
LAB_1062e0f9:
    diag_error(n);
    lo = 0;
    hi = 0;
  }
  else {
    if (4 < count) {
      n = 0xf;
      goto LAB_1062e0f9;
    }
    lo = 0;
    hi = 0;
    uVar5 = (uint)count;
    if (count != 0) {
      do {
        uVar2 = *chars;
        chars = (ushort *)((int)chars + 1);
        lVar8 = _allshl(8,lo,hi);
        hi = (uint)((ulonglong)lVar8 >> 0x20);
        lo = (uint)lVar8 | (uint)(byte)uVar2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    if ((g_opt_J_unsigned_char == '\0') && (count == 1)) {
      lo = (uint)(char)lo;
      hi = (int)lo >> 0x1f;
    }
  }
  g_yylval = (uint)g_type_int;
LAB_1062034a:
  _g_yylval_word2 = lo;
  _g_yylval_word3 = hi;
  if (g_token_arena_index == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    puVar3 = g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    a = g_arenas + g_token_arena_index;
    puVar3 = a->cur;
    puVar1 = g_arenas[g_token_arena_index].end;
    a->cur = puVar3 + 0x20;
    if (puVar1 < puVar3 + 0x20) {
      arena_grow(a);
    }
  }
  if (puVar3 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *puVar3 = 'e';
  puVar6 = &g_yylval;
  puVar7 = (uint *)(puVar3 + 8);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  return puVar3;
}

