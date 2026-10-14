int __cdecl expr_build_generated_operator_delete_call(c1_node *p,char is_array)

{
  c1_lookup_result *pcVar1;
  c1_lookup_entry *pcVar2;
  c1_node *args;
  c1_node *callee;
  int iVar3;
  void *name;
  c1_symbol *sym;
  
  name = g_name_array_delete;
  if (is_array == '\0') {
    name = g_name_delete;
  }
  pcVar1 = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (pcVar1 == (c1_lookup_result *)0x0) {
LAB_10419d50:
    pcVar1 = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_delete,1);
    if (pcVar1 == (c1_lookup_result *)0x0) {
      sym = (c1_symbol *)0x0;
      goto LAB_10419d28;
    }
    pcVar2 = lookup_check_ambiguous_symbol(pcVar1,'\x01');
    if (pcVar2 == (c1_lookup_entry *)0x0) {
      iVar3 = expr_build_operator_delete_call_not_found(p);
      return iVar3;
    }
  }
  else {
    pcVar2 = lookup_check_ambiguous_symbol(pcVar1,'\x01');
    if (pcVar2 == (c1_lookup_entry *)0x0) goto LAB_10419d50;
  }
  sym = pcVar2->sym;
LAB_10419d28:
  args = tree_append_list_item((c1_node *)0x0,p,2);
  callee = tree_new_symbol_ref(sym,'\0');
  iVar3 = expr_build_call(callee,args);
  return iVar3;
}

