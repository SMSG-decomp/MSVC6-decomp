void __thiscall decl_state_unwind_to(c1_scope_stack *stack,c1_decl_state *entry)

{
  c1_decl_state **ppcVar1;
  c1_decl_state *pcVar2;
  c1_decl_state *pcVar3;
  
  pcVar2 = stack->saved;
  pcVar3 = pcVar2;
  if (pcVar2 != (c1_decl_state *)0x0) {
    while (pcVar3 != entry) {
      ppcVar1 = &pcVar3->next;
      pcVar3 = *ppcVar1;
      if (*ppcVar1 == (c1_decl_state *)0x0) {
        return;
      }
    }
    if (pcVar3 != (c1_decl_state *)0x0) {
      decl_state_restore(stack,pcVar2->kept);
      decl_state_pop(stack);
      while (pcVar2 != entry) {
        pcVar2 = stack->saved;
        decl_state_restore(stack,pcVar2->kept);
        decl_state_pop(stack);
      }
    }
  }
  return;
}

