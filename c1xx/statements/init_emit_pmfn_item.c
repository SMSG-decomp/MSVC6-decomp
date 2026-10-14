void __cdecl init_emit_pmfn_item(c1_symbol *sym)

{
  c1_node *pcVar1;
  void *name;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar2;
  c1_symbol *local_8;
  c1_symbol *local_4;
  
  if (sym == (c1_symbol *)0x0) {
    local_8 = sym;
    local_4 = sym;
    pcVar1 = tree_new_constant(g_type_int,&local_8,g_expr_arena_index);
    init_process_initializer(pcVar1,(int)sym);
    return;
  }
  if (g_pmfn_type == (c1_type *)0x0) {
    name = name_intern("_PMFN");
    result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar2 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar2 = lookup_check_ambiguous_symbol(result,'\x01');
    }
    g_pmfn_type = pcVar2->sym->type;
  }
  special_member_need_definition(sym);
  pcVar1 = expr_reference_named_entity(sym,1);
  pcVar1 = (c1_node *)expr_build_unary(0x31,pcVar1);
  pcVar1->type = g_pmfn_type;
  init_process_initializer(pcVar1,1);
  return;
}

