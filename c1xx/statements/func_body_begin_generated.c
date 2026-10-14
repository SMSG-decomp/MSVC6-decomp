void __cdecl func_body_begin_generated(c1_symbol *fn)

{
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20;
  g_current_function = func_body_begin(fn);
  func_body_begin_emit();
  func_flow_state_push(g_current_function,(void *)0x0);
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  func_begin_compound_statement();
  g_current_function->flags2 = g_current_function->flags2 | 4;
  g_block_depth = '\0';
  g_current_function->flags1 = g_current_function->flags1 & 0xfe | 2;
  return;
}

