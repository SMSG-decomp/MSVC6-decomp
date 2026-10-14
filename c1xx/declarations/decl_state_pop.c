void __fastcall decl_state_pop(c1_scope_stack *stack)

{
  if (stack->saved != (c1_decl_state *)0x0) {
    stack->saved = stack->saved->next;
  }
  return;
}

