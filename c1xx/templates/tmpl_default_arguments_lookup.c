int * __cdecl tmpl_default_arguments_lookup(void *tmpl)

{
  int *piVar1;
  
  if (g_template_default_arguments != (c1_symtab *)0x0) {
    piVar1 = symtab_lookup(g_template_default_arguments,tmpl);
    return piVar1;
  }
  return (int *)0x0;
}

