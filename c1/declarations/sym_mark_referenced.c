void __fastcall sym_mark_referenced(c1_symbol *sym)

{
  uint uVar1;
  c1_u8 cVar2;
  c1_symbol_cell *init_head;
  c1_symbol_cell *old_head;
  uchar *cell;
  
  uVar1 = sym->key_ref;
  if (((byte)uVar1 & 3) < 3) {
    sym->key_ref = (uVar1 + 1 ^ uVar1) & 3 ^ uVar1;
  }
  sym->key_ref = (g_idb_outside_function & 1) << 2 | sym->key_ref & 0xfffffffb;
  cell = g_arenas[0].cur;
  if (g_pch_record_references == '\0') {
    if ((g_pch_use_only != 0) && ((sym->kind & 0x20) == 0)) {
      cVar2 = sym_is_deferrable(sym);
      if (cVar2 != '\0') {
        sym_defer_emission(sym);
      }
    }
  }
  else if (g_current_function == (c1_symbol *)0x0) {
    if ((g_init_symbol != (c1_symbol *)0x0) && ((sym->flags2 & 2) == 0)) {
      init_head = (g_init_symbol->x2c).references;
      g_arenas[0].cur = g_arenas[0].cur + 8;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(c1_symbol **)cell = sym;
      *(c1_symbol_cell **)(cell + 4) = init_head;
      (g_init_symbol->x2c).references = (c1_symbol_cell *)cell;
      return;
    }
  }
  else if ((g_current_function != sym) && ((sym->flags2 & 2) == 0)) {
    old_head = ((g_current_function->x28).function)->references;
    g_arenas[0].cur = g_arenas[0].cur + 8;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_symbol **)cell = sym;
    *(c1_symbol_cell **)(cell + 4) = old_head;
    ((g_current_function->x28).function)->references = cell;
    return;
  }
  return;
}

