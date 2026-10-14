c1xx_hash_scope * __thiscall scope_enclosing_namespace(c1_scope_stack *stack,char null_if_global)

{
  c1_u8 cVar1;
  c1xx_hash_scope *pcVar2;
  
  pcVar2 = (c1xx_hash_scope *)stack->current;
  cVar1 = pcVar2->kind;
  while (cVar1 != '\0') {
    pcVar2 = (c1xx_hash_scope *)pcVar2->outer;
    cVar1 = pcVar2->kind;
  }
  if ((pcVar2->outer == (c1xx_scope *)0x0) && (null_if_global != '\0')) {
    pcVar2 = (c1xx_hash_scope *)0x0;
  }
  return pcVar2;
}

