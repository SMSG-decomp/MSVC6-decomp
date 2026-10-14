void __thiscall ns_enter_enclosing_namespaces(void *stack,c1_symbol *ns)

{
  c1xx_hash_scope *pcVar1;
  
  if (ns != *(c1_symbol **)((int)stack + 0x220)) {
    for (pcVar1 = scope_enclosing_namespace(stack,'\0');
        (pcVar1 != (c1xx_hash_scope *)0x0 && (pcVar1->kind == '\0'));
        pcVar1 = (c1xx_hash_scope *)pcVar1->outer) {
      if (pcVar1 == *(c1xx_hash_scope **)ns->type) {
        return;
      }
    }
    if ((ns->scope_index != 0) &&
       ((g_scope_vector->entries[(short)ns->scope_index]->kind & 0x1f) == 0x19)) {
      ns_enter_enclosing_namespaces(stack,g_scope_vector->entries[(short)ns->scope_index]);
    }
    scope_push_child(stack,*(c1xx_scope **)ns->type);
  }
  return;
}

