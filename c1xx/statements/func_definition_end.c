void __cdecl func_definition_end(char push_dynamic_init)

{
  if (g_current_function != (c1_symbol *)0x0) {
    g_block_depth = '\x02';
    scope_end_block();
    func_emit_end(g_compile_flags_c8 >> 7 & 1);
    if (push_dynamic_init != '\0') {
      vector_push(g_dynamic_initializer_functions,g_current_function);
    }
  }
  g_current_function = (c1_symbol *)0x0;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffdffdf;
  return;
}

