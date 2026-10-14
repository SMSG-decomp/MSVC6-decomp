c1_token * __cdecl yylex_c(void)

{
  byte bVar1;
  c1_token *pcVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  c1_yystype *pcVar6;
  
  pcVar2 = token_next(&g_token_position);
  bVar1 = (&g_token_class)[pcVar2->code];
  uVar4 = g_compile_flags_c4;
  iVar3 = g_paren_depth;
joined_r0x10604b15:
  g_compile_flags_c4 = uVar4;
  if (bVar1 < 0xbb) {
    g_paren_depth = iVar3;
    switch((&switchD_10604b29::switchdataD_10604ca0)[bVar1]) {
    case 0:
    case 0x6d:
      if (g_yylex_end_seen != '\0') {
        pch_check_after_options();
        return g_token_end_marker;
      }
      g_yylex_end_seen = '\x01';
      return g_token_end_of_file;
    case 6:
      g_compile_flags_c4 = uVar4 | 0x400;
      pcVar2 = yylex_classify_identifier(pcVar2);
      uVar4 = g_compile_flags_c4 & 0xfffffbff;
      if (pcVar2->code == '\x1e') {
        g_compile_flags_c4 = uVar4;
        pcVar2 = decl_specifier_from_tag(pcVar2);
        return pcVar2;
      }
      if ((g_compile_flags_c4 & 0x10000000) != 0) {
        g_compile_flags_c4 = uVar4;
        return pcVar2;
      }
      g_compile_flags_c4 = uVar4;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      return pcVar2;
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x28:
    case 0xba:
      pcVar2 = decl_specifier_from_tag(pcVar2);
      return pcVar2;
    case 0x24:
      if ((((g_paren_level_flags[iVar3] & 2) != 0) && ((uVar4 & 0x8000000) != 0)) &&
         ((pcVar2->value).words[4] != 0)) {
        g_yylval = *(uint *)((pcVar2->value).words[4] + 8);
        if (g_token_arena_index == 0) {
          pcVar2 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
        }
        else {
          pcVar2 = arena_alloc(g_arenas + g_token_arena_index,0x20);
        }
        if (pcVar2 != (c1_token *)0x0) {
          pcVar2->code = '\x06';
          puVar5 = &g_yylval;
          pcVar6 = &pcVar2->value;
          for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
            pcVar6->words[0] = *puVar5;
            puVar5 = puVar5 + 1;
            pcVar6 = (c1_yystype *)((int)pcVar6 + 4);
          }
          return pcVar2;
        }
        return (c1_token *)0x0;
      }
      g_compile_flags_c4 = uVar4 | 1;
      if ((uVar4 & 0x10000000) == 0) {
        g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 2;
        return pcVar2;
      }
      break;
    case 0x76:
      if ((uVar4 & 0x10000000) == 0) {
        g_paren_depth = iVar3 + 1;
        if (0x3b < g_paren_depth) {
          diag_fatal_simple(0xd);
        }
        (&g_paren_level_pending)[g_paren_depth] = 0;
        g_paren_level_flags[iVar3 + 1] = '\0';
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return pcVar2;
    case 0x7d:
      if ((uVar4 & 0x10000000) == 0) {
        g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 2;
        g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 1;
        return pcVar2;
      }
      break;
    case 0x7e:
      g_compile_flags_c4 = uVar4 & 0xfffffffe;
      if ((iVar3 == 0) && ((uVar4 & 0x10000000) == 0)) goto code_r0x10627681;
      break;
    case 0x81:
      g_sizeof_depth = g_sizeof_depth + 1;
    case 0x2c:
    case 0x31:
    case 0x3c:
    case 0x46:
    case 0x4a:
    case 0x51:
    case 0x59:
    case 0x65:
    case 0x73:
    case 0x78:
      if ((uVar4 & 0x10000000) == 0) {
        g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 2;
        return pcVar2;
      }
    }
  }
  g_paren_depth = iVar3;
  return pcVar2;
code_r0x10627681:
  diag_error(0x3b,0x4c,(uint)pcVar2->code);
  pcVar2 = token_next(&g_token_position);
  bVar1 = (&g_token_class)[pcVar2->code];
  uVar4 = g_compile_flags_c4;
  iVar3 = g_paren_depth;
  goto joined_r0x10604b15;
}

