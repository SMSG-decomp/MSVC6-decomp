void * __cdecl name_intern_symbol_decorated(c1_symbol *sym)

{
  char *s;
  void *pvVar1;
  
  s = decorate_name(sym,(c1_symbol *)0x0);
  pvVar1 = name_intern(s);
  return pvVar1;
}

