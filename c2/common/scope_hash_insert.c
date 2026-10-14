void __fastcall scope_hash_insert(c2_scope_table *scope,c2_fe_symbol *s)

{
  c2_fe_symbol *pcVar1;
  uint uVar2;
  
  uVar2 = s->id & 0x3ff;
  pcVar1 = scope->buckets[uVar2];
  scope->buckets[uVar2] = s;
  s->next = pcVar1;
  return;
}

