c1_type * __cdecl expr_uuidof_return_type(void)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  
  if (g_com_uuidof_return_type == (c1_type *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_COMuuidofReturnType,1);
    if (result != (c1_lookup_result *)0x0) {
      pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
      g_com_uuidof_return_type = pcVar1->sym->type;
      return g_com_uuidof_return_type;
    }
    g_com_uuidof_return_type = *(c1_type **)(iRam00000000 + 0x14);
  }
  return g_com_uuidof_return_type;
}

