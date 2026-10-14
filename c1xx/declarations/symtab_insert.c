void __cdecl symtab_insert(c1_symtab *tab,void *key,void *value)

{
  c1_u32 cVar1;
  c1_symtab_entry *pcVar2;
  uint bucket;
  c1_symtab_entry *pcVar3;
  c1_arena *a;
  
  bucket = hash_table_bucket(tab,key);
  pcVar3 = symtab_find_in_bucket(tab,key,bucket);
  if (pcVar3 != (c1_symtab_entry *)0x0) {
    pcVar3->value = value;
    return;
  }
  cVar1 = tab->arena;
  if (cVar1 == 0) {
    if (g_symtab_entry_pool_left < 0xc) {
      pool_reserve((c1xx_pool *)&g_symtab_entry_pool,0xc);
    }
    g_symtab_entry_pool_left = g_symtab_entry_pool_left - 0xc;
    pcVar3 = g_symtab_entry_pool;
    g_symtab_entry_pool = g_symtab_entry_pool + 1;
  }
  else {
    a = g_arenas + cVar1;
    pcVar3 = (c1_symtab_entry *)a->cur;
    pcVar2 = (c1_symtab_entry *)g_arenas[cVar1].end;
    a->cur = (c1_u8 *)(pcVar3 + 1);
    if (pcVar2 < pcVar3 + 1) {
      arena_grow(a);
    }
  }
  pcVar3->key = key;
  pcVar3->next = tab->buckets[bucket];
  tab->buckets[bucket] = pcVar3;
  tab->count = tab->count + 1;
  pcVar3->value = value;
  return;
}

