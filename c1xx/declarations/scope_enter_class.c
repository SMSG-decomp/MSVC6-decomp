void __thiscall scope_enter_class(c1_scope_stack *stack,c1_symbol *sym)

{
  byte bVar1;
  c1_symbol *pcVar2;
  
  if (((stack->current->kind != '\0') || (pcVar2 = scope_current_namespace(stack), pcVar2 != sym))
     && ((stack->current->kind != 0xff || ((c1_symbol *)(stack->current->body).symbols != sym)))) {
    pcVar2 = (c1_symbol *)0x0;
    if (sym->scope_index != 0) {
      pcVar2 = g_scope_vector->entries[(short)sym->scope_index];
      scope_enter_symbol_scope(pcVar2);
    }
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
      lookup_check_symbol_kind(stack,&sym->kind,(int)sym->name,pcVar2 == (c1_symbol *)0x0);
    }
  }
  return;
}

