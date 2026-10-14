void __cdecl tmpl_set_default_arguments(c1_arg_list *defaults,c1_symbol *tmpl)

{
  if ((tmpl->flags3 & 4) == 0) {
    if (g_template_default_arguments == (c1_symtab *)0x0) {
      g_template_default_arguments = symtab_new(0x10,0,9,8,'\x01','\x01');
    }
    symtab_insert(g_template_default_arguments,tmpl,defaults);
  }
  return;
}

