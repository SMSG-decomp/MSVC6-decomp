void __thiscall decl_state_restore(c1_scope_stack *stack,char unused)

{
  c1_u8 cVar1;
  c1_decl_state *pcVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint local_4;
  
  pcVar2 = stack->saved;
  if (pcVar2 != (c1_decl_state *)0x0) {
    stack->current = pcVar2->current;
    cVar1 = pcVar2->depth;
    stack->depth = cVar1;
    if (pcVar2->kept != '\0') {
      bVar4 = 1;
      local_4 = 1;
      if (cVar1 != '\0') {
        do {
          uVar3 = local_4;
          bVar5 = bVar4 - 1;
          bVar4 = bVar4 + 1;
          local_4 = (uint)bVar4;
          stack->contexts[uVar3] = stack->saved->contexts[bVar5];
        } while (bVar4 <= stack->depth);
      }
      pcVar2 = stack->saved;
      stack->qual_class = pcVar2->qual_class;
      stack->access_op = pcVar2->access_op;
      stack->qualified = pcVar2->qualified;
      stack->reported = pcVar2->reported;
      stack->keep_aliases = pcVar2->keep_aliases;
    }
  }
  return;
}

