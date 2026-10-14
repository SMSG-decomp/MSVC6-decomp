void __fastcall fe_symbol_hash_insert(c2_fe_symbol *fsym,int local_scope)

{
  c2_fe_symbol *pcVar1;
  uint uVar2;
  
  uVar2 = fsym->id & 0x3ff;
  if (local_scope != 0) {
    pcVar1 = g_cur_scope->buckets[uVar2];
    g_cur_scope->buckets[uVar2] = fsym;
    fsym->next = pcVar1;
    return;
  }
  pcVar1 = g_global_scope.buckets[uVar2];
  g_global_scope.buckets[uVar2] = fsym;
  fsym->next = pcVar1;
  return;
}

