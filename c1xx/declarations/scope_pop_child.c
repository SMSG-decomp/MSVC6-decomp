void __fastcall scope_pop_child(c1_scope_stack *stack)

{
  scope_pop_block(stack);
  if (stack->current->usings != (c1_using_directive *)0x0) {
    scope_pop_using_directives(stack->current);
  }
  stack->current = stack->current->outer;
  return;
}

