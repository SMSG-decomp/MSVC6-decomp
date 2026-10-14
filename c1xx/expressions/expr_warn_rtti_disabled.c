c1_node * __cdecl expr_warn_rtti_disabled(c1_node *e,c1_symbol *cls)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_node *pcVar2;
  c1_node *callee;
  c1_type *type;
  
  if (g_rtti == '\0') {
    diag_warning(1,0x21d,0x79,cls->type);
  }
  if (PTR_104d21bc == (c1_symbol *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_RTtypeid,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar1 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    PTR_104d21bc = pcVar1->sym;
  }
  pcVar2 = expr_build_address_of(e,8);
  if ((((cls->detail).cls)->layout_flags3a & 0x40) == 0) {
    pcVar2 = expr_vfptr_subobject_address(100,pcVar2,cls);
  }
  pcVar2 = tree_new_cast(PTR_104d152c,pcVar2);
  pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,2);
  callee = tree_new_symbol_ref(PTR_104d21bc,'\0');
  pcVar2 = (c1_node *)expr_build_call(callee,pcVar2);
  type = expr_typeid_return_type();
  pcVar2 = tree_new_cast(type,pcVar2);
  pcVar2 = expr_build_builtin_unary(0x3d,pcVar2);
  return pcVar2;
}

