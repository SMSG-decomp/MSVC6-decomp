void * __cdecl symtab_lookup(fe_symtab *tab,void *key)

{
  uint bucket;
  fe_symtab_entry *pfVar1;
  
  if (tab != (fe_symtab *)0x0) {
    bucket = hash_table_bucket(tab,key);
    pfVar1 = symtab_find_in_bucket(tab,key,bucket);
    if (pfVar1 != (fe_symtab_entry *)0x0) {
      return pfVar1->value;
    }
  }
  return (void *)0x0;
}

