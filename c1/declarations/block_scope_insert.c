void __thiscall block_scope_insert(c1_scope_object *block,c1_symbol *sym)

{
  void **ppvVar1;
  
  sym->flags2 = sym->flags2 | 2;
  ppvVar1 = (block->entries).buckets;
  (*block->vtbl->link)(block,(int)sym);
  if (ppvVar1 == (void **)0x0) {
    scope_push_block(g_current_scope,block);
  }
  return;
}

