c1_token * __cdecl pragma_check_on_off(void)

{
  byte bVar1;
  c1_token *pcVar2;
  c1_token *pcVar3;
  c1_type *pcVar4;
  uint uVar5;
  c1_type *pcVar6;
  fe_arena *a;
  int iVar7;
  char *pcVar8;
  uint *puVar9;
  c1_yystype *pcVar10;
  bool bVar11;
  
  pcVar3 = pragma_warn_expected_token('\x06');
  if (pcVar3 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar8 = "on";
  pcVar6 = ((pcVar3->value).node)->type;
  pcVar4 = pcVar6;
  do {
    bVar1 = (byte)pcVar4->code;
    bVar11 = bVar1 < (byte)*pcVar8;
    if (bVar1 != *pcVar8) {
LAB_1062195c:
      uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_10621961;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)&pcVar4->code + 1);
    bVar11 = bVar1 < (byte)pcVar8[1];
    if (bVar1 != pcVar8[1]) goto LAB_1062195c;
    pcVar4 = (c1_type *)&pcVar4->flags;
    pcVar8 = pcVar8 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_10621961:
  if (uVar5 == 0) {
    g_yylval = 1;
    g_yylval_word1 = uVar5;
    if (g_token_arena_index != 0) {
      pcVar3 = arena_alloc(g_arenas + g_token_arena_index,0x20);
      goto LAB_106219d5;
    }
  }
  else {
    pcVar8 = "off";
    do {
      bVar1 = (byte)pcVar6->code;
      bVar11 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1062a53b:
        uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_1062199a;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)&pcVar6->code + 1);
      bVar11 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1062a53b;
      pcVar6 = (c1_type *)&pcVar6->flags;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    uVar5 = 0;
LAB_1062199a:
    if (uVar5 != 0) {
      diag_warning(1,0x55);
      return (c1_token *)0x0;
    }
    g_yylval = uVar5;
    g_yylval_word1 = uVar5;
    if (g_token_arena_index != 0) {
      a = g_arenas + g_token_arena_index;
      pcVar3 = (c1_token *)a->cur;
      pcVar2 = (c1_token *)g_arenas[g_token_arena_index].end;
      a->cur = &pcVar3[1].code;
      if (pcVar2 < pcVar3 + 1) {
        arena_grow(a);
      }
      goto LAB_106219d5;
    }
  }
  if (g_pool_default.left < 0x20) {
    pool_reserve(&g_pool_default,0x20);
  }
  g_pool_default.left = g_pool_default.left - 0x20;
  pcVar3 = (c1_token *)g_pool_default.cur;
  g_pool_default.cur = g_pool_default.cur + 0x20;
LAB_106219d5:
  if (pcVar3 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar3->code = 'e';
  puVar9 = &g_yylval;
  pcVar10 = &pcVar3->value;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    pcVar10->words[0] = *puVar9;
    puVar9 = puVar9 + 1;
    pcVar10 = (c1_yystype *)((int)pcVar10 + 4);
  }
  return pcVar3;
}

