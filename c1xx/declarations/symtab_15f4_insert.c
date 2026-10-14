void __cdecl symtab_15f4_insert(c1_symbol *key,void *value)

{
  if ((key->flags3 & 4) == 0) {
    if (g_instance_arguments_table == (c1_symtab *)0x0) {
      g_instance_arguments_table = symtab_new(0x10,0,8,7,'\x01','\x01');
    }
    symtab_insert(g_instance_arguments_table,key,value);
  }
  return;
}

