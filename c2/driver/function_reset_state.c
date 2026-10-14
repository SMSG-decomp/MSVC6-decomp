void function_reset_state(void)

{
  clear_reg_symbol_flag10();
  symbol_pools_reset();
  clear_node_free_lists();
  g_jumpopt_no_crossjump = 1;
  g_floats_used = '\0';
  g_cur_function = (c2_function *)0x0;
  if (g_opt_incremental != 0) {
    clear_float_constant_pool();
  }
  g_alias_tables_valid = 0;
  return;
}

