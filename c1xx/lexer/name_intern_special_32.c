void * __cdecl name_intern_special_32(c1_symbol *sym)

{
  char *s;
  void *pvVar1;
  
  s = decorate_special_name(&sym->kind,'2');
  pvVar1 = name_intern(s);
  return pvVar1;
}

