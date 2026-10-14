void * __cdecl symtab_lookup(c1_symtab *tab,void *key)

{
  uint bucket;
  c1_symtab_entry *pcVar1;
  
  if (tab != (c1_symtab *)0x0) {
    bucket = hash_table_bucket(tab,key);
    pcVar1 = symtab_find_in_bucket(tab,key,bucket);
    if (pcVar1 != (c1_symtab_entry *)0x0) {
      return pcVar1->value;
    }
  }
  return (void *)0x0;
}

