int __cdecl sym_list_1b58_value(c1_symbol *key)

{
  void *pvVar1;
  
  pvVar1 = sym_list_1b58_lookup(key);
  return *(int *)((int)pvVar1 + 4);
}

