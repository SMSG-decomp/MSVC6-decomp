c1_symbol * __thiscall tmpl_check_reference_parameter(c1_symbol *sym,c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  diag_error(0x37c,sym);
  pcVar1 = sym_finish_new(sym,d);
  return pcVar1;
}

