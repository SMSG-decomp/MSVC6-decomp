void * __cdecl name_intern_rtti_locator_name(int vftable_sym)

{
  char *s;
  void *pvVar1;
  
  s = decorate_rtti_locator_name((c1_symbol *)vftable_sym);
  pvVar1 = name_intern(s);
  return pvVar1;
}

