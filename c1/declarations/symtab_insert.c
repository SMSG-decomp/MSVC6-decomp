void __cdecl symtab_insert(fe_symtab *tab,void *key,void *value)

{
  uint uVar1;
  fe_symtab_entry *pfVar2;
  uint bucket;
  fe_symtab_entry *pfVar3;
  fe_arena *a;
  
  bucket = hash_table_bucket(tab,key);
  pfVar3 = symtab_find_in_bucket(tab,key,bucket);
  if (pfVar3 != (fe_symtab_entry *)0x0) {
    pfVar3->value = value;
    return;
  }
  uVar1 = tab->arena;
  if (uVar1 == 0) {
    if (g_symtab_entry_pool.left < 0xc) {
      pool_reserve(&g_symtab_entry_pool,0xc);
    }
    g_symtab_entry_pool.left = g_symtab_entry_pool.left - 0xc;
    pfVar3 = (fe_symtab_entry *)g_symtab_entry_pool.cur;
    g_symtab_entry_pool.cur = g_symtab_entry_pool.cur + 0xc;
  }
  else {
    a = g_arenas + uVar1;
    pfVar3 = (fe_symtab_entry *)a->cur;
    pfVar2 = (fe_symtab_entry *)g_arenas[uVar1].end;
    a->cur = (uchar *)(pfVar3 + 1);
    if (pfVar2 < pfVar3 + 1) {
      arena_grow(a);
    }
  }
  pfVar3->key = key;
  pfVar3->next = tab->buckets[bucket];
  tab->buckets[bucket] = pfVar3;
  tab->count = tab->count + 1;
  pfVar3->value = value;
  return;
}

