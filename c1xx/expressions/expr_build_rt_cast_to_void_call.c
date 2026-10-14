c1_node * __cdecl
expr_build_rt_cast_to_void_call(c1_node *node,c1_type *target,c1_symbol *source_class)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1_node *pcVar2;
  c1_node *callee;
  
  if (PTR_104d2828 == (c1_symbol *)0x0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)
                       (g_current_scope->global_scope,g_name_RTCastToVoid,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar1 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    PTR_104d2828 = pcVar1->sym;
  }
  if ((((source_class->detail).cls)->layout_flags3a & 0x40) == 0) {
    node = expr_vfptr_subobject_address(0xde,node,source_class);
  }
  pcVar2 = tree_new_cast(PTR_104d152c,node);
  pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,2);
  callee = tree_new_symbol_ref(PTR_104d2828,'\0');
  pcVar2 = (c1_node *)expr_build_call(callee,pcVar2);
  pcVar2->type = target;
  return pcVar2;
}

