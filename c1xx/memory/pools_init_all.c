void __cdecl pools_init_all(void)

{
  pool_init_on_arena(&g_function_record_pool,0);
  pool_init_on_arena(&g_scope_pool,0);
  pool_init_on_arena(&g_type_entry_pool,0);
  pool_init_on_arena(&g_unused_pool,0);
  pool_init_on_arena(&g_function_params_pool,0);
  pool_init_on_arena(&g_symtab_entry_pool,0);
  pool_init_on_arena(&g_name_pool,0);
  pool_init_on_arena(&g_type_list_pool,0);
  pool_init_on_arena(&g_macro_definition_pool,0);
  pool_init_on_arena(&g_pool_default,0);
  return;
}

