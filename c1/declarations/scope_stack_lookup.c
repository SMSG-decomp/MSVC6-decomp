c1_scope_lookup * __thiscall scope_stack_lookup(c1_scope_stack *scopes,int name)

{
  c1_scope_lookup *pcVar1;
  byte bVar2;
  
  bVar2 = scopes->depth;
  pcVar1 = (*scopes->objects[bVar2]->vtbl->lookup_by_kind)(scopes->objects[bVar2],name);
  if (pcVar1 == (c1_scope_lookup *)0x0) {
    while( true ) {
      if (bVar2 == 0) break;
      pcVar1 = (*scopes->objects[(byte)(bVar2 - 1)]->vtbl->lookup_by_kind)
                         (scopes->objects[(byte)(bVar2 - 1)],name);
      bVar2 = bVar2 - 1;
      if (pcVar1 != (c1_scope_lookup *)0x0) {
        return pcVar1;
      }
    }
    pcVar1 = (c1_scope_lookup *)0x0;
  }
  return pcVar1;
}

