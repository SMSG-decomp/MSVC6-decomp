c1_symtab_entry * __cdecl symtab_find_in_bucket(c1_symtab *tab,void *key,int bucket)

{
  c1_symtab_entry *pcVar1;
  char cVar2;
  c1_symtab_equal_fn equal;
  
  equal = (c1_symtab_equal_fn)(&PTR_symtab_equal_0_104bc4ac)[tab->compare];
  pcVar1 = tab->buckets[bucket];
  while( true ) {
    if (pcVar1 == (c1_symtab_entry *)0x0) {
      return (c1_symtab_entry *)0x0;
    }
    cVar2 = (*equal)(key,pcVar1->key);
    if (cVar2 != '\0') break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}

