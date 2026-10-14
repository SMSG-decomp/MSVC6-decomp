void * __cdecl class_friend_table_lookup(void *key)

{
  void *pvVar1;
  
  pvVar1 = symtab_lookup(g_friend_table,key);
  return pvVar1;
}

