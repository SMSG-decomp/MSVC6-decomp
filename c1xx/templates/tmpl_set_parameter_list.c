void __cdecl tmpl_set_parameter_list(c1_sym_list *params,c1_symbol *tmpl)

{
  if ((tmpl->flags3 & 4) == 0) {
    if (PTR_104d15f0 == (c1_symtab *)0x0) {
      PTR_104d15f0 = symtab_new(0x10,0,7,6,'\x01','\x01');
    }
    symtab_insert(PTR_104d15f0,tmpl,params);
  }
  return;
}

