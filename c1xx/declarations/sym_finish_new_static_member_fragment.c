c1_symbol * __thiscall
sym_finish_new_static_member_fragment(void *tmpl_datum,c1_symbol *sym,c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  symtab_15f4_insert(sym,tmpl_datum);
  pcVar1 = sym_finish_new(sym,d);
  return pcVar1;
}

