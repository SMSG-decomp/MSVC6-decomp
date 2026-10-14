c1_sym_list * __fastcall scope_pop_if_kind1(c1_scope_stack *stack)

{
  c1_sym_list *pcVar1;
  
  if (stack->current->kind == '\x01') {
    pcVar1 = (stack->current->body).symbols;
    scope_pop_child(stack);
    return pcVar1;
  }
  return (c1_sym_list *)0x0;
}

