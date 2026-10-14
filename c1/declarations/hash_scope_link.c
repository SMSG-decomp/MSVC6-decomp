void __thiscall hash_scope_link(c1_scope_object *hash_scope,c1_symbol *sym)

{
  uint uVar1;
  
  uVar1 = hash_scope->mask & sym->name->flags & 0xffff;
  sym->next = (hash_scope->entries).buckets[uVar1];
  (hash_scope->entries).buckets[uVar1] = &sym->name;
  return;
}

