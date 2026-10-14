void __cdecl class_friend_table_add(void *rec)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = class_friend_table_lookup(rec);
  if (pvVar3 == (void *)0x0) {
    symtab_insert(g_friend_table,rec,rec);
    return;
  }
  pvVar2 = *(void **)((int)pvVar3 + 8);
  while (pvVar1 = pvVar2, pvVar1 != (void *)0x0) {
    pvVar3 = pvVar1;
    pvVar2 = *(void **)((int)pvVar1 + 8);
  }
  *(void **)((int)pvVar3 + 8) = rec;
  return;
}

