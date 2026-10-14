void __cdecl arena_select_for_expressions(void)

{
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return;
}

