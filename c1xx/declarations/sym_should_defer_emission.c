char __cdecl sym_should_defer_emission(c1_symbol *sym)

{
  char cVar1;
  
  if ((((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
      ((g_compile_flags_cc & 0x100000) == 0)) &&
     (((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)))) {
    cVar1 = sym_is_deferrable(sym);
    return cVar1;
  }
  return '\0';
}

