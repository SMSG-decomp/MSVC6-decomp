char * __cdecl lex_lookahead_decl_specifiers(char *token)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  c1_u32 *scan_word;
  c1xx_decl_specifiers *pcVar6;
  c1_decl_spec_scan scan;
  
  scan_word = (c1_u32 *)&scan;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *scan_word = 0;
    scan_word = scan_word + 1;
  }
  scan.token = (c1_u8 *)token;
  pcVar2 = decl_scan_specifier_tokens(&scan);
  iVar3 = g_paren_depth;
  if (*scan.token == 'v') {
    if ((scan.spec[0] & 0x10) != 0) goto LAB_10406f28;
    if ((g_compile_flags_c4 & 0x80000000) == 0) {
      if ((scan.spec[0] & 7) != 7) {
        if (((g_paren_level_flags[g_paren_depth] & 8) == 0) ||
           (((g_compile_flags_c8 & 0x20000000) != 0 &&
            ((g_paren_level_flags[g_paren_depth] & 0x20) != 0)))) {
          if ((scan.basic_type == 0) || (scan.has_declspec == '\0')) {
            pcVar2 = lex_mark_paren_candidate((char *)scan.result);
            if ((*pcVar2 == -0x27) && (2 < scan.ntokens)) {
              decl_record_reset_default_int(&scan);
              iVar3 = g_paren_depth;
              puVar5 = &g_yylval;
              pcVar6 = g_paren_level_declspecs + g_paren_depth;
              for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
                *(uint *)pcVar6->spec = *puVar5;
                puVar5 = puVar5 + 1;
                pcVar6 = (c1xx_decl_specifiers *)(pcVar6->spec + 4);
              }
              g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 1;
            }
            return pcVar2;
          }
        }
        else if (((byte)g_compile_flags_cc & 0x10) != 0) {
          pcVar2 = parse_action_tail_ee16((char *)scan.result);
          return pcVar2;
        }
      }
      goto LAB_10406f28;
    }
  }
  else if ((g_compile_flags_c4 & 0x80000000) == 0) goto LAB_10406f28;
  g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
LAB_10406f28:
  if (((*pcVar2 == '$') || (*pcVar2 == -0x1b)) && ((g_compile_flags_c4 & 0x10000000) == 0)) {
    bVar1 = g_paren_level_flags[g_paren_depth];
    g_paren_level_flags[g_paren_depth] = bVar1 | 2;
    if ((bVar1 & 0x80) != 0) {
      g_paren_level_flags[iVar3] = bVar1 & 0x7e | 3;
    }
  }
  return pcVar2;
}

