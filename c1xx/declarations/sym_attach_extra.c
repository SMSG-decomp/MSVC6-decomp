void __cdecl sym_attach_extra(c1_symbol *sym,void *value)

{
  if (g_declspec_record_table == (c1_symtab *)0x0) {
    g_declspec_record_table = symtab_new(0x1f,0,0,2,'\x01','\x01');
  }
  symtab_insert(g_declspec_record_table,sym,value);
  sym->flags21 = sym->flags21 | 0x40;
  return;
}

