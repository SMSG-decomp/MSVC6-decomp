void __thiscall scope_push_child(c1_scope_stack *scopes,c1_scope_object *scope)

{
  scope->parent = scopes->current;
  scopes->current = scope;
  scope_push_block(scopes,scope);
  return;
}

