void __cdecl pools_reset(void)

{
  pool_clear((int *)&g_function_record_pool);
  pool_init_on_arena(&g_function_record_pool,0);
  pool_clear((int *)&g_scope_pool);
  pool_init_on_arena(&g_scope_pool,0);
  pool_clear(&g_type_entry_pool);
  pool_init_on_arena(&g_type_entry_pool,0);
  pool_clear((int *)&g_unused_pool);
  pool_init_on_arena(&g_unused_pool,0);
  pool_clear((int *)&g_function_params_pool);
  pool_init_on_arena(&g_function_params_pool,0);
  pool_clear((int *)&g_symtab_entry_pool);
  pool_init_on_arena(&g_symtab_entry_pool,0);
  pool_clear((int *)&g_name_pool);
  pool_init_on_arena(&g_name_pool,0);
  pool_clear((int *)&g_type_list_pool);
  pool_init_on_arena(&g_type_list_pool,0);
  pool_clear((int *)&g_macro_definition_pool);
  pool_init_on_arena(&g_macro_definition_pool,0);
  pool_clear((int *)&g_pool_default);
  pool_init_on_arena(&g_pool_default,0);
  return;
}

