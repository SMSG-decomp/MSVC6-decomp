void __thiscall scope_push_child(c1_scope_stack *stack,c1xx_scope *scope)

{
  scope->outer = stack->current;
  stack->current = scope;
  scope_push_block(stack,scope);
  return;
}

