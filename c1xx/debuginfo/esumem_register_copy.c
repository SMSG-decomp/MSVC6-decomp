void __cdecl esumem_register_copy(c1_symbol *member,c1_symbol *copy)

{
  fe_name *key;
  
  if (PTR_104d16c8 == (c1_symtab *)0x0) {
    PTR_104d16c8 = symtab_new(0x1f,0,2,1,'\x01','\x01');
  }
  symtab_insert(PTR_104d16c8,member,copy);
  key = copy->name;
  if (g_esumem_copy_table == (c1_symtab *)0x0) {
    g_esumem_copy_table = symtab_new(0x1f,0,1,0,'\x01','\x01');
  }
  symtab_insert(g_esumem_copy_table,key,member);
  return;
}

