void __thiscall scope_pop_to_kind(c1_scope_stack *stack,char p2)

{
  byte bVar1;
  
  bVar1 = stack->current->kind;
  if (0xfa < bVar1) {
    while (bVar1 != 0xfd) {
      if ((p2 != '\0') && (bVar1 != 0xfe)) {
        if (stack->current->kind != 0xfc) {
          return;
        }
        scope_pop_child(stack);
        return;
      }
      scope_pop_child(stack);
      bVar1 = stack->current->kind;
      if (bVar1 < 0xfb) {
        return;
      }
    }
  }
  return;
}

