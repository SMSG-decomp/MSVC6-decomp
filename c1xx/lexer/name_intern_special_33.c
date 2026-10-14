void * __cdecl name_intern_special_33(void *sym)

{
  char *s;
  void *pvVar1;
  
  s = decorate_special_name(sym,'3');
  pvVar1 = name_intern(s);
  return pvVar1;
}

