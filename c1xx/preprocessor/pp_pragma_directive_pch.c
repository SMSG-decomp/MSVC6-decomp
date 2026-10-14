int __cdecl pp_pragma_directive_pch(void)

{
  c1_u8 *pcVar1;
  int iVar2;
  
  pp_capture_directive_text();
  iVar2 = pch_record_or_match_directive();
  if (iVar2 != 1) {
    pcVar1 = pp_pragma_directive();
    return (int)pcVar1;
  }
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return g_token_newline;
    }
    return g_token_newline;
  }
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  return g_token_newline;
}

