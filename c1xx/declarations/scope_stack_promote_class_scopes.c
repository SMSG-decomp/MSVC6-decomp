void __thiscall scope_stack_promote_class_scopes(c1_scope_stack *stack)

{
  c1xx_scope *pcVar1;
  c1_u8 innermost;
  
  innermost = '\x01';
  pcVar1 = stack->current;
  if (pcVar1 != stack->global_scope) {
    do {
      if (pcVar1->kind == 0xfd) {
        return;
      }
      if (0xfa < pcVar1->kind) {
        *(c1_u8 *)&pcVar1[1].outer = innermost;
        innermost = '\0';
        pcVar1->kind = 0xff;
      }
      pcVar1 = pcVar1->outer;
    } while (pcVar1 != stack->global_scope);
  }
  return;
}

