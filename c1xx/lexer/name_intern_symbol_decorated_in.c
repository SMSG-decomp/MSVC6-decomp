void * __cdecl name_intern_symbol_decorated_in(c1_symbol *scope_sym,c1_symbol *sym)

{
  char *s;
  void *pvVar1;
  
  s = decorate_name(sym,scope_sym);
  pvVar1 = name_intern(s);
  return pvVar1;
}

