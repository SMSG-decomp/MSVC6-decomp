void function_cleanup_reset(void)

{
  g_fe_symbol_bytes[1] = 0;
  arena_reset(1);
  g_unused_function_word = 0;
  g_cur_func_sym = (c2_fe_symbol *)0x0;
  g_cur_scope = (c2_scope_table *)0x0;
  return;
}

