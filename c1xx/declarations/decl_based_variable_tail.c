c1_symbol * __thiscall decl_based_variable_tail(c1_symbol *sym,c1_declarator *d)

{
  decl_define_variable(sym);
  decl_assign_data_segment_and_check(d);
  g_file_scope_decl_since_body = 1;
  return d->sym;
}

