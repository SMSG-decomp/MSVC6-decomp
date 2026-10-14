c1_u8 * __thiscall
scope_lookup_tag_current_or_namespace(c1_scope_stack *stack,fe_name *name,char in_namespace)

{
  char cVar1;
  c1xx_scope *scope;
  c1_type *pcVar2;
  c1_lookup_entry *pcVar3;
  c1xx_hash_scope *scope_00;
  c1_u8 *pcVar4;
  
  if (in_namespace != '\0') {
    scope_00 = scope_enclosing_namespace(stack,'\0');
    pcVar4 = (*scope_00->vtbl->lookup_tag)(scope_00,name);
    return pcVar4;
  }
  scope = stack->current;
  if (0xfa < scope->kind) {
    pcVar2 = ((scope->body).cls)->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    if ((pcVar2->code & 0x100) != 0) {
      return (c1_u8 *)0x0;
    }
  }
  pcVar3 = (*scope->vtbl->lookup_tag)(scope,name);
  return (c1_u8 *)pcVar3;
}

