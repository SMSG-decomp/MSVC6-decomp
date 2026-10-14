void __cdecl tu_defer_symbols_in_list(c1_symbol_cell *list)

{
  c1_symbol_cell *pcVar1;
  c1_symbol *sym;
  c1_u8 cVar2;
  
  while( true ) {
    if (list == (c1_symbol_cell *)0x0) {
      return;
    }
    pcVar1 = list->next;
    sym = list->sym;
    if (sym == (c1_symbol *)0x0) break;
    list = pcVar1;
    if (((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) &&
       (cVar2 = sym_is_deferrable(sym), cVar2 != '\0')) {
      sym_defer_emission(sym);
    }
  }
  return;
}

