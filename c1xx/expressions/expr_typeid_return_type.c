c1_type * __cdecl expr_typeid_return_type(void)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  
  if (g_rt_typeid_return_type == (c1_type *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_RTtypeidReturnType,1);
    if (result != (c1_lookup_result *)0x0) {
      pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
      g_rt_typeid_return_type = sym_word_14(pcVar1->sym);
      return g_rt_typeid_return_type;
    }
    g_rt_typeid_return_type = sym_word_14(pcRam00000000);
  }
  return g_rt_typeid_return_type;
}

