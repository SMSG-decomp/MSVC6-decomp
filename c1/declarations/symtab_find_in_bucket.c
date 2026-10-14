fe_symtab_entry * __cdecl symtab_find_in_bucket(fe_symtab *tab,void *key,int bucket)

{
  code *pcVar1;
  fe_symtab_entry *pfVar2;
  char cVar3;
  
  pcVar1 = (code *)(&PTR_hash_key_equal_10652268)[tab->compare];
  pfVar2 = tab->buckets[bucket];
  while( true ) {
    if (pfVar2 == (fe_symtab_entry *)0x0) {
      return (fe_symtab_entry *)0x0;
    }
    cVar3 = (*pcVar1)(key,pfVar2->key);
    if (cVar3 != '\0') break;
    pfVar2 = pfVar2->next;
  }
  return pfVar2;
}

