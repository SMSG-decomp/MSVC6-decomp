void __cdecl tmpl_set_warning_state(c1_symbol *tmpl,int *warning_snapshot)

{
  if (PTR_104d160c == (c1_symtab *)0x0) {
    PTR_104d160c = symtab_new(0x10,0,0xd,0xc,'\x01','\x01');
  }
  symtab_insert(PTR_104d160c,tmpl,warning_snapshot);
  return;
}

