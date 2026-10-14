void __fastcall scope_pop_child(c1_scope_stack *scopes)

{
  scope_pop_block(scopes);
  scopes->current = scopes->current->parent;
  return;
}

