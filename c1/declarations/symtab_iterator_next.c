char __cdecl symtab_iterator_next(fe_symtab_iter *it)

{
  uint uVar1;
  fe_symtab_entry *pfVar2;
  
  if (it->entry == (fe_symtab_entry *)0x0) {
    do {
      uVar1 = it->next_bucket;
      if (it->tab->nbuckets <= uVar1) {
        return '\0';
      }
      pfVar2 = it->tab->buckets[uVar1];
      it->next_bucket = uVar1 + 1;
      it->entry = pfVar2;
    } while (pfVar2 == (fe_symtab_entry *)0x0);
  }
  pfVar2 = it->entry;
  it->key = pfVar2->key;
  it->value = pfVar2->value;
  it->entry = pfVar2->next;
  return '\x01';
}

