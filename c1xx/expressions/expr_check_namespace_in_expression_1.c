c1_node * __cdecl
expr_check_namespace_in_expression_1(c1_symbol *sym,void **set_entry,c1_symbol *entry_sym)

{
  c1_node *pcVar1;
  
  set_entry[2] = g_scope_vector->entries[(short)entry_sym->key_ref];
  if ((sym->kind & 0x1f) != 0x19) {
    pcVar1 = sym_is_data_or_function(sym);
    return pcVar1;
  }
  diag_error(0x372);
  return (c1_node *)0x0;
}

