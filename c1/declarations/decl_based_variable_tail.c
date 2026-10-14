c1_symbol * __cdecl decl_based_variable_tail(c1_symbol *sym,c1_declaration *decl)

{
  decl_define_variable(sym);
  type_check_based_allocation(decl);
  g_file_scope_decl_since_body = 1;
  return decl->sym;
}

