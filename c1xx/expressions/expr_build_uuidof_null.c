c1_node * __cdecl expr_build_uuidof_null(void)

{
  fe_name *name;
  c1_symbol *guid_sym;
  c1_node *pcVar1;
  c1_guid *guid;
  
  if ((g_uuidof_null_guid_guard & 1) == 0) {
    g_uuidof_null_guid_guard = g_uuidof_null_guid_guard | 1;
    c1xx_atexit(&expr_uuidof_null_guid_dtor);
  }
  guid = &g_uuidof_null_guid;
  name = guid_format_symbol_name(&g_uuidof_null_guid);
  guid_sym = expr_uuidof_guid_symbol(name,guid);
  pcVar1 = expr_uuidof_guid_value(guid_sym);
  return pcVar1;
}

