c1_tag_lookup * __thiscall scope_stack_lookup_tag(c1_scope_stack *scopes,int name)

{
  int name_00;
  c1_tag_lookup *pcVar1;
  byte bVar2;
  bool bVar3;
  
  name_00 = name;
  if ((name != 0) && ((fe_name *)name != g_name_unnamed)) {
    bVar2 = scopes->depth;
    do {
      name = (int)bVar2;
      pcVar1 = (*scopes->objects[name]->vtbl->lookup_tag)(scopes->objects[name],name_00);
      if (pcVar1 != (c1_tag_lookup *)0x0) {
        g_tag_found_in_current_scope = (uint)(bVar2 == scopes->depth);
        return pcVar1;
      }
      bVar3 = bVar2 != 0;
      bVar2 = bVar2 - 1;
    } while (bVar3);
    g_tag_found_in_current_scope = 0;
  }
  return (c1_tag_lookup *)0x0;
}

