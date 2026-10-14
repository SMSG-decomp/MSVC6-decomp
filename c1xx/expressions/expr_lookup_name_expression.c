c1_node * __cdecl expr_lookup_name_expression(void *name)

{
  c1_symbol *entry_sym;
  c1_lookup_entry *pcVar1;
  c1_node *pcVar2;
  c1_symbol *sym;
  
  pcVar1 = lookup_name_in_context(g_current_scope,name,0x133);
  if (pcVar1 == (c1_lookup_entry *)0x0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = pcVar1->sym;
  }
  if (sym == (c1_symbol *)0x0) {
    if (name == g_name_most_derived) {
      pcVar2 = class_layout_vtable_this();
      return pcVar2;
    }
    sym = expr_report_undeclared_identifier(name);
    if (sym == (c1_symbol *)0x0) {
      sym = sym_new_object(name,'\0');
      sym->flags3 = sym->flags3 | 4;
    }
  }
  if (((sym->flags2 & 0x20) != 0) &&
     (((sym->flags2 & 0x10) != 0 ||
      (((g_current_function != (c1_symbol *)0x0 && ((g_current_function->flags1 & 4) != 0)) &&
       (g_scope_vector->entries[(short)g_current_function->scope_index]->name == name)))))) {
    sym = sym_hiding_partner(sym);
  }
  if ((sym->kind & 0x1f) == 0x12) {
    entry_sym = (*(void ***)sym->type)[2];
    if ((entry_sym->kind & 0x1f) == 0xf) {
      pcVar2 = expr_check_namespace_in_expression_1(sym,*(void ***)sym->type,entry_sym);
      return pcVar2;
    }
  }
  if ((sym->kind & 0x1f) != 0x19) {
    pcVar2 = sym_is_data_or_function(sym);
    return pcVar2;
  }
  diag_error(0x372);
  return (c1_node *)0x0;
}

