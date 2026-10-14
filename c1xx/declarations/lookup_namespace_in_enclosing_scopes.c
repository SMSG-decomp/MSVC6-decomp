c1_lookup_entry * __thiscall
lookup_namespace_in_enclosing_scopes(c1_scope_stack *stack,c1_namespace_symbol *ns)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  c1xx_scope *scope;
  
  scope = stack->current;
  while ((((scope->kind != '\0' ||
           (result = (*scope->vtbl->lookup)(scope,ns->name,2), result == (c1_lookup_result *)0x0))
          || (pcVar1 = lookup_check_ambiguous_symbol(result,'\0'), pcVar1 == (c1_lookup_entry *)0x0)
          ) || (pcVar1->sym != (c1_symbol *)ns))) {
    scope = scope->outer;
    if (scope == (c1xx_scope *)0x0) {
      return (c1_lookup_entry *)0x0;
    }
  }
  if (pcVar1->scope == scope) {
    return pcVar1;
  }
  pcVar1->scope = scope;
  return pcVar1;
}

