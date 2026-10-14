void * __cdecl name_intern_decorated_quiet(c1_symbol *sym,int *args)

{
  char *s;
  void *pvVar1;
  int saved_errors;
  
  saved_errors = g_error_count;
  g_error_count = 0;
  s = decorate_name_2(sym,args);
  pvVar1 = name_intern(s);
  *(uint *)((int)pvVar1 + 8) = *(uint *)((int)pvVar1 + 8) | 0x2020000;
  g_error_count = saved_errors;
  return pvVar1;
}

