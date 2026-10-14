int __cdecl lookup_in_enclosing_scopes(char p1,int cls,int member,int *owner)

{
  c1_symbol *scope_cls;
  int iVar1;
  
  if ((p1 == '\0') || ((*(byte *)(member + 0x21) & 2) == 0)) {
    scope_cls = g_scope_vector->entries[*(short *)(member + 6)];
  }
  else {
    scope_cls = g_scope_vector->entries[*(short *)(member + 0x2a)];
  }
  if (owner != (int *)0x0) {
    *owner = (int)scope_cls;
  }
  if (scope_cls == (c1_symbol *)cls) {
    return 0;
  }
  iVar1 = lookup_operator_function((c1_symbol *)cls,(int)scope_cls);
  return iVar1;
}

