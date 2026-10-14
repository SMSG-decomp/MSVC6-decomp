void __thiscall scope_construct(c1xx_scope *scope,c1_u8 kind,c1xx_scope *parent)

{
  scope->kind = kind;
  scope->outer = (c1xx_scope *)0x0;
  scope->parent = parent;
  scope->usings = (c1_using_directive *)0x0;
  scope->vtbl = (c1xx_scope_vtbl *)&PTR_vtable_true_al_104c4e34;
  return;
}

