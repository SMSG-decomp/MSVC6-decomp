void * __fastcall decl_pop_parameter_scope(void *scopes)

{
  void *pvVar1;
  
  if (*(char *)(*(int *)((int)scopes + 4) + 8) == '\x01') {
    pvVar1 = *(void **)(*(int *)((int)scopes + 4) + 0x10);
    scope_pop_child(scopes);
    return pvVar1;
  }
  return (void *)0x0;
}

