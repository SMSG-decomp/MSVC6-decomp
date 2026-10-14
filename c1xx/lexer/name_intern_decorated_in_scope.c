void * __cdecl name_intern_decorated_in_scope(void *sym2,c1_symbol *sym)

{
  char *s;
  void *pvVar1;
  
  sym->name = g_name_local_static_destructor;
  sym->flags1 = sym->flags1 & 0xfc;
  s = decorate_name(sym,sym2);
  pvVar1 = name_intern(s);
  return pvVar1;
}

