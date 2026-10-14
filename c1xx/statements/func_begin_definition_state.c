void __cdecl func_begin_definition_state(int *pos)

{
  if ((g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  g_pending_parameter_scope = (c1_sym_list *)*pos;
  g_pending_function_word = pos[1];
  g_compile_flags_c4 = g_compile_flags_c4 | 0x300;
  return;
}

