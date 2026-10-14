c1_u8 * __cdecl lex_scan_character_constant(int wide,ushort *chars,ushort count)

{
  c1_u8 *pcVar1;
  ushort uVar2;
  c1_arena *a;
  c1_u8 *pcVar3;
  int iVar4;
  uint lo;
  uint uVar5;
  uint hi;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  c1_type local_10;
  
  if (wide != 0) {
    lo = (uint)*chars;
    hi = 0;
    if (4 < count) {
      diag_warning(3,0x42);
    }
    g_yylval = (uint)g_type_unsigned_short;
    goto LAB_10426458;
  }
  if (count == 0) {
    diag_error(0x89);
    lo = 0;
    hi = 0;
LAB_10462c5c:
    g_yylval = (uint)g_type_int;
  }
  else {
    if (count < 5) {
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
      if (g_opt_J_unsigned_char != '\0') goto LAB_10462c91;
      if (count != 1) goto LAB_10462c5c;
      lo = (uint)(char)lo;
      hi = (int)lo >> 0x1f;
    }
    else {
      diag_error(0xf);
      lo = 0;
      hi = 0;
LAB_10462c91:
      if (count != 1) goto LAB_10462c5c;
    }
    local_10.code = (-(ushort)(g_opt_J_unsigned_char != '\0') & 0x2000) + 0x11;
    local_10.base = (c1_type *)0x0;
    local_10.debug_index = 0;
    local_10.flags = 0;
    local_10.extra.cls = (c1_symbol *)0x0;
    g_yylval = (uint)type_intern(&local_10);
  }
LAB_10426458:
  _g_yylval_word2 = lo;
  _g_yylval_word3 = hi;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar3 = a->cur;
    pcVar1 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar3 + 0x30;
    if (pcVar1 < pcVar3 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar3 = 'e';
  puVar6 = &g_yylval;
  puVar7 = (uint *)(pcVar3 + 8);
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  return pcVar3;
}

