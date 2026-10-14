c1_tag_lookup * __thiscall scope_lookup_tag_here(c1_scope_stack *scopes,int name,char file_scope)

{
  c1_tag_lookup *pcVar1;
  
  if (file_scope == '\0') {
    pcVar1 = (*scopes->current->vtbl->lookup_tag)(scopes->current,name);
    return pcVar1;
  }
  pcVar1 = (*scopes->file_scope->vtbl->lookup_tag)(scopes->file_scope,name);
  return pcVar1;
}

