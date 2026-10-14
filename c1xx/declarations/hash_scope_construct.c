c1xx_hash_scope * __thiscall
hash_scope_construct(c1xx_hash_scope *scope,c1_u32 mask,c1_u8 kind,c1xx_scope *parent)

{
  scope->kind = kind;
  scope->parent = parent;
  scope->outer = (c1xx_scope *)0x0;
  scope->usings = (c1_using_directive *)0x0;
  scope->mask = mask;
  scope->using_list = (c1_using_cell **)0x0;
  scope->vtbl = (c1xx_hash_scope_vtbl *)&PTR_hash_scope_has_entries_104bd894;
  return scope;
}

