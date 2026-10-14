void pools_reset(void)

{
  pool_clear((fe_pool *)&g_function_record_pool);
  pool_init_on_arena((fe_pool *)&g_function_record_pool,0);
  pool_clear(&g_scope_pool);
  pool_init_on_arena(&g_scope_pool,0);
  pool_clear((fe_pool *)&g_type_entry_pool);
  pool_init_on_arena((fe_pool *)&g_type_entry_pool,0);
  pool_clear((fe_pool *)&g_spare_pool);
  pool_init_on_arena((fe_pool *)&g_spare_pool,0);
  pool_clear((fe_pool *)&g_function_type_entry_pool);
  pool_init_on_arena((fe_pool *)&g_function_type_entry_pool,0);
  pool_clear(&g_symtab_entry_pool);
  pool_init_on_arena(&g_symtab_entry_pool,0);
  pool_clear(&g_name_pool);
  pool_init_on_arena(&g_name_pool,0);
  pool_clear(&g_macro_definition_pool);
  pool_init_on_arena(&g_macro_definition_pool,0);
  pool_clear(&g_pool_default);
  pool_init_on_arena(&g_pool_default,0);
  return;
}

