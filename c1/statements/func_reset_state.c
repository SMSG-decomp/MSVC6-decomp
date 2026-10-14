void __cdecl func_reset_state(void)

{
  g_pending_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_function_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_pending_function_word = 0;
  g_function_context_word = 0;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffdffff | 0x800000;
  g_current_function = (c1_symbol *)0x0;
  return;
}

