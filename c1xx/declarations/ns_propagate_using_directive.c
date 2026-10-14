void __thiscall
ns_propagate_using_directive
          (c1_scope_stack *stack,c1_namespace_symbol *ns,c1_namespace_symbol *nominated,
          c1_namespace_symbol *skip)

{
  c1_using_cell **ppcVar1;
  c1xx_hash_scope *scope;
  c1_using_cell *pcVar2;
  c1_using_cell *pcVar3;
  
  ppcVar1 = ((c1xx_hash_scope *)stack->global_scope)->using_list;
  if (ppcVar1 != (c1_using_cell **)0x0) {
    for (pcVar3 = *ppcVar1; pcVar3 != (c1_using_cell *)0x0; pcVar3 = pcVar3->next) {
      if (pcVar3->ns == ns) {
        if (pcVar3 != (c1_using_cell *)0x0) {
          ns_add_using_namespace((c1xx_hash_scope *)stack->global_scope,nominated,skip);
        }
        break;
      }
    }
  }
  if (stack->using_namespaces != (c1_using_cell **)0x0) {
    pcVar3 = *stack->using_namespaces;
    do {
      scope = pcVar3->ns->info->scope;
      ppcVar1 = scope->using_list;
      if (ppcVar1 != (c1_using_cell **)0x0) {
        for (pcVar2 = *ppcVar1; pcVar2 != (c1_using_cell *)0x0; pcVar2 = pcVar2->next) {
          if (pcVar2->ns == ns) {
            if (pcVar2 != (c1_using_cell *)0x0) {
              ns_add_using_namespace(scope,nominated,skip);
            }
            break;
          }
        }
      }
      pcVar3 = pcVar3->next;
    } while (pcVar3 != (c1_using_cell *)0x0);
  }
  return;
}

