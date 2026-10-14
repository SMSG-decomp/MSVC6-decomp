void __cdecl decl_record_file_scope_twin(c1_symbol *key,void *value)

{
  if (g_file_scope_twins == (fe_symtab *)0x0) {
    g_file_scope_twins = symtab_new(0x1f,2,2,1,'\x01','\x01');
  }
  symtab_insert(g_file_scope_twins,key,value);
  return;
}

