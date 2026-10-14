void __thiscall scope_push_block(c1_scope_stack *stack,c1xx_scope *scope)

{
  char cVar1;
  byte bVar2;
  
  if (stack->contexts[stack->depth] != scope) {
    cVar1 = (*scope->vtbl->has_entries)();
    if (cVar1 != '\0') {
      bVar2 = stack->depth + 1;
      stack->depth = bVar2;
      if (0x7f < bVar2) {
        diag_fatal_simple(0x3d);
      }
      stack->contexts[stack->depth] = scope;
    }
  }
  return;
}

