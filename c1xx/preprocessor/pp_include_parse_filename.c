char * __cdecl pp_include_parse_filename(char report,char *angle)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  
  iVar2 = g_opt_E_preprocess;
  g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
  g_opt_E_preprocess = 0;
  pbVar3 = token_next((c1_token_reader *)&g_token_position);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
  bVar1 = *pbVar3;
  g_opt_E_preprocess = iVar2;
  if (bVar1 == 7) {
    if (((pbVar3[0xe] & 1) != 0) && (report != '\0')) {
      diag_error(2);
    }
    pcVar4 = *(char **)(pbVar3 + 8);
    if (angle != (char *)0x0) {
      *angle = '\0';
    }
    return pcVar4;
  }
  if (bVar1 == 0x44) {
    pcVar4 = pp_include_parse_angle_name(report);
    if (pcVar4 != (char *)0x0) {
      if (angle == (char *)0x0) {
        return pcVar4;
      }
      *angle = '\x01';
      return pcVar4;
    }
    lex_skip_whitespace();
  }
  else {
    if (report != '\0') {
      diag_error(6,g_token_spelling[bVar1]);
    }
    lex_skip_whitespace();
  }
  if (report != '\0') {
    if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
        ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) {
      if (((g_compile_flags_c8 & 0x4000000) == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
        if (((byte)g_compile_flags_cc & 1) == 0) {
          g_expr_arena_index = 5;
          g_context_arena_index = 5;
          return (char *)0x0;
        }
        g_context_arena_index = 4;
        g_expr_arena_index = 4;
        g_compile_flags_c4 = g_compile_flags_c4;
        g_compile_flags_c8 = g_compile_flags_c8;
        g_compile_flags_cc._0_1_ = (byte)g_compile_flags_cc;
        g_opt_E_preprocess = g_opt_E_preprocess;
        return (char *)0x0;
      }
    }
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return (char *)0x0;
}

