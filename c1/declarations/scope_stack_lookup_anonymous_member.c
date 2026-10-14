c1_symbol * __thiscall scope_stack_lookup_anonymous_member(void *scopes,int name)

{
  byte bVar1;
  bool bVar2;
  uint local_8;
  c1_symbol *local_4;
  
  local_4 = (c1_symbol *)0x0;
  bVar1 = *(byte *)((int)scopes + 0x208);
  do {
    local_8 = (uint)bVar1;
    (**(code **)(**(int **)((int)scopes + local_8 * 4 + 8) + 0x14))(name,&local_4);
    bVar2 = bVar1 != 0;
    bVar1 = bVar1 - 1;
  } while (bVar2);
  return local_4;
}

