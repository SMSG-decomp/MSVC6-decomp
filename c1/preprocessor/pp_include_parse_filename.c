char * __cdecl pp_include_parse_filename(char report,char *angle)

{
  byte bVar1;
  int iVar2;
  c1_token *pcVar3;
  char *pcVar4;
  
  iVar2 = g_opt_E_preprocess;
  g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
  g_opt_E_preprocess = 0;
  pcVar3 = token_next(&g_token_position);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
  bVar1 = pcVar3->code;
  g_opt_E_preprocess = iVar2;
  if (bVar1 == 7) {
    if ((((uint)(pcVar3->value).spec.words.segment & 0x10000) != 0) && (report != '\0')) {
      diag_error(2);
    }
    pcVar4 = (pcVar3->value).ptr;
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
  }
  else if (report != '\0') {
    diag_error(6,g_token_spelling[bVar1]);
  }
  lex_skip_whitespace();
  if (report != '\0') {
    g_context_arena_index = 3;
    g_expr_arena_index = 3;
  }
  return (char *)0x0;
}

