c1_u8 * __cdecl pp_scan_directive_fragment(void)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  pp_skip_line_comments();
  iVar2 = pch_record_or_match_directive();
  if (iVar2 == 1) {
    g_context_arena_index = 3;
    g_expr_arena_index = 3;
    return g_token_newline;
  }
  pcVar1 = pp_pragma_directive();
  return pcVar1;
}

