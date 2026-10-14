void __fastcall scope_pop_block(c1_scope_stack *stack)

{
  char cVar1;
  
  cVar1 = (*stack->current->vtbl->has_entries)();
  if (cVar1 != '\0') {
    if (stack->current != stack->contexts[stack->depth]) {
      diag_fatal_simple(0x1fa);
    }
    stack->contexts[stack->depth] = (c1xx_scope *)0x0;
    stack->depth = stack->depth + 0xff;
  }
  return;
}

