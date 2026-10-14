c1_symbol * __cdecl decl_lookup_file_scope_twin(c1_symbol *sym)

{
  c1_symbol *pcVar1;
  
  pcVar1 = symtab_lookup(g_file_scope_twins,sym);
  return pcVar1;
}

