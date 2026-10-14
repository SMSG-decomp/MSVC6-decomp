void __cdecl symtab_21f4_insert(c1_symbol *key,void *value)

{
  if (g_inline_instance_table == (c1_symtab *)0x0) {
    g_inline_instance_table = symtab_new(0x1f,4,2,1,'\x01','\x01');
  }
  symtab_insert(g_inline_instance_table,key,value);
  return;
}

