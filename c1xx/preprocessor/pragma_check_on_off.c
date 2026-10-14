c1_u8 * __cdecl pragma_check_on_off(void)

{
  byte bVar1;
  c1_u8 *pcVar2;
  uchar *puVar3;
  uint uVar4;
  byte *pbVar5;
  c1_arena *a;
  byte *pbVar6;
  c1_u8 *pcVar7;
  int iVar8;
  char *pcVar9;
  uint *src;
  uint *puVar10;
  bool bVar11;
  
  puVar3 = pragma_warn_expected_token('\x06');
  if (puVar3 == (uchar *)0x0) {
    return (c1_u8 *)0x0;
  }
  pcVar9 = "on";
  pbVar5 = *(byte **)(*(int *)(puVar3 + 8) + 4);
  pbVar6 = pbVar5;
  do {
    bVar1 = *pbVar6;
    bVar11 = bVar1 < (byte)*pcVar9;
    if (bVar1 != *pcVar9) {
LAB_1044e54e:
      uVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_1044e553;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar6[1];
    bVar11 = bVar1 < (byte)pcVar9[1];
    if (bVar1 != pcVar9[1]) goto LAB_1044e54e;
    pbVar6 = pbVar6 + 2;
    pcVar9 = pcVar9 + 2;
  } while (bVar1 != 0);
  uVar4 = 0;
LAB_1044e553:
  if (uVar4 == 0) {
    g_yylval = 1;
    g_yylval_word1 = uVar4;
    if (g_token_arena_index != 0) {
      pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      goto LAB_1044e5c7;
    }
  }
  else {
    pcVar9 = "off";
    do {
      bVar1 = *pbVar5;
      bVar11 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_1045e795:
        uVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_1044e58c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar11 = bVar1 < (byte)pcVar9[1];
      if (bVar1 != pcVar9[1]) goto LAB_1045e795;
      pbVar5 = pbVar5 + 2;
      pcVar9 = pcVar9 + 2;
    } while (bVar1 != 0);
    uVar4 = 0;
LAB_1044e58c:
    if (uVar4 != 0) {
      diag_warning(1,0x55);
      return (c1_u8 *)0x0;
    }
    g_yylval = uVar4;
    g_yylval_word1 = uVar4;
    if (g_token_arena_index != 0) {
      a = g_arenas + g_token_arena_index;
      pcVar7 = a->cur;
      pcVar2 = g_arenas[g_token_arena_index].end;
      a->cur = pcVar7 + 0x30;
      if (pcVar2 < pcVar7 + 0x30) {
        arena_grow(a);
      }
      goto LAB_1044e5c7;
    }
  }
  if (g_pool_default_left < 0x30) {
    pool_reserve((c1xx_pool *)&g_pool_default,0x30);
  }
  g_pool_default_left = g_pool_default_left - 0x30;
  pcVar7 = g_pool_default;
  g_pool_default = g_pool_default + 0x30;
LAB_1044e5c7:
  if (pcVar7 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar7 = 'e';
  src = &g_yylval;
  puVar10 = (uint *)(pcVar7 + 8);
  for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = *src;
    src = src + 1;
    puVar10 = puVar10 + 1;
  }
  return pcVar7;
}

