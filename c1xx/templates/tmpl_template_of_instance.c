void * __cdecl tmpl_template_of_instance(c1_symbol *key)

{
  void *pvVar1;
  
  if (g_instance_template_table != (c1_symtab *)0x0) {
    pvVar1 = symtab_lookup(g_instance_template_table,key);
    return pvVar1;
  }
  return (void *)0x0;
}

