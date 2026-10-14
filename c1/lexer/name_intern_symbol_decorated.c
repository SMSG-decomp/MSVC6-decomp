fe_name * __cdecl name_intern_symbol_decorated(c1_symbol *sym)

{
  char *s;
  fe_name *pfVar1;
  
  s = decorate_name(sym,g_block_scope_number);
  pfVar1 = name_intern(s);
  return pfVar1;
}

