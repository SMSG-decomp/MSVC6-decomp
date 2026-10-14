void __thiscall scope_pop_to_kind_if_needed(c1_scope_stack *stack,char p2)

{
  byte bVar1;
  
  bVar1 = stack->current->kind;
  if ((0xfa < bVar1) && (bVar1 != 0xfd)) {
    scope_pop_to_kind(stack,p2);
  }
  return;
}

