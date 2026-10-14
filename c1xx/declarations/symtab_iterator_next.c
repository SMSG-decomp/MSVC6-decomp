c1_u8 __cdecl symtab_iterator_next(c1_symtab_iter *it)

{
  c1_symtab_entry *pcVar1;
  uint uVar2;
  
  if (it->entry == (c1_symtab_entry *)0x0) {
    do {
      uVar2 = it->next_bucket;
      if (it->tab->nbuckets <= uVar2) {
        return '\0';
      }
      pcVar1 = it->tab->buckets[uVar2];
      it->next_bucket = uVar2 + 1;
      it->entry = pcVar1;
    } while (pcVar1 == (c1_symtab_entry *)0x0);
  }
  pcVar1 = it->entry;
  it->key = pcVar1->key;
  it->value = pcVar1->value;
  it->entry = pcVar1->next;
  return '\x01';
}

