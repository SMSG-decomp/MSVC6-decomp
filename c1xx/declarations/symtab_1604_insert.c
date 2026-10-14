void __cdecl symtab_1604_insert(c1_symbol *key,void *value)

{
  if ((key->flags3 & 4) == 0) {
    if (g_instance_template_table == (c1_symtab *)0x0) {
      g_instance_template_table = symtab_new(0x10,0,0xc,0xb,'\x01','\x01');
    }
    symtab_insert(g_instance_template_table,key,value);
  }
  return;
}

