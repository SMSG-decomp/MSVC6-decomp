void __thiscall hash_scope_link(c1xx_hash_scope *scope,c1_symbol *sym)

{
  uint uVar1;
  
  uVar1 = scope->mask & sym->name->flags & 0xffff;
  sym->next = (c1_symbol *)scope->buckets[uVar1];
  scope->buckets[uVar1] = (c1_sym_link *)&sym->name;
  return;
}

