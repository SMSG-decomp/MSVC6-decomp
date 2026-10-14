c1xx_class_scope * __thiscall lookup_overload_member(c1_scope_stack *stack,c1_symbol *sym,int kind)

{
  char cVar1;
  c1xx_class_scope *pcVar2;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1xx_class_scope *)0x0;
  }
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  cVar1 = lookup_is_type_or_member_of_type(sym);
  if (cVar1 != '\0') {
    cVar1 = (*stack->current->vtbl->has_entries)();
    if ((cVar1 == '\0') && (stack->current->kind < 0xfb)) {
      hash_scope_make_table_and_push(stack->current);
    }
    if (kind != 0xfd) {
      pcVar2 = class_scope_new(stack,4,(c1_u8)kind,sym);
      return pcVar2;
    }
    pcVar2 = class_scope_new(stack,0,0xfd,sym);
    return pcVar2;
  }
  return (c1xx_class_scope *)0x0;
}

