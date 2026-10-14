void __cdecl sym_list_emit_deferred(int *list)

{
  int *piVar1;
  c1_symbol *sym;
  char cVar2;
  
  while( true ) {
    if (list == (int *)0x0) {
      return;
    }
    piVar1 = (int *)list[1];
    sym = (c1_symbol *)*list;
    if (sym == (c1_symbol *)0x0) break;
    list = piVar1;
    if ((((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
        ((g_compile_flags_cc & 0x100000) == 0)) &&
       ((((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
        (cVar2 = sym_is_deferrable(sym), cVar2 != '\0')))) {
      sym_defer_emission(sym);
    }
  }
  return;
}

