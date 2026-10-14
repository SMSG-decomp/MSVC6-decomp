c1_type * __cdecl expr_guid_object_type(void)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  
  if (g_s_guid_type == (c1_type *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_s_GUID,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar1 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    g_s_guid_type = pcVar1->sym->type;
    g_s_guid_type = type_strip_qualifiers_unless_all(g_s_guid_type,0x20);
  }
  return g_s_guid_type;
}

