c1_symbol * __fastcall scope_current_namespace(c1_scope_stack *stack)

{
  c1xx_scope *pcVar1;
  
  pcVar1 = stack->current;
  if (pcVar1->kind == 0xfa) {
    pcVar1 = pcVar1->outer;
  }
  if (pcVar1->kind != '\0') {
    return (c1_symbol *)0x0;
  }
  if (pcVar1->outer != (c1xx_scope *)0x0) {
    return *(c1_symbol **)&pcVar1[1].kind;
  }
  return (c1_symbol *)0x0;
}

