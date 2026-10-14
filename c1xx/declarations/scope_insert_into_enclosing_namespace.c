void __thiscall scope_insert_into_enclosing_namespace(c1_scope_stack *stack,c1_symbol *sym)

{
  c1xx_hash_scope *scope;
  
  scope = scope_enclosing_namespace(stack,'\0');
  (*scope->vtbl->insert)(scope,sym);
  return;
}

