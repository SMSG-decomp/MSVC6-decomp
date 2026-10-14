void __fastcall sym_mark_referenced(c1_symbol *sym)

{
  char cVar1;
  void **dep_cell_2;
  void **dep_cell;
  void *dep_head;
  void *dep_head_2;
  uint key_ref;
  
  key_ref = sym->key_ref;
  if (((byte)key_ref & 3) < 3) {
    sym->key_ref = (key_ref + 1 ^ key_ref) & 3 ^ key_ref;
  }
  sym->key_ref = (g_idb_outside_function & 1) << 2 | sym->key_ref & 0xfffffffb;
  if (g_pch_create_explicit == 0) {
    cVar1 = sym_should_defer_emission(sym);
    if (cVar1 != '\0') {
      sym_defer_emission(sym);
    }
  }
  else if (g_current_function == (c1_symbol *)0x0) {
    if ((g_init_symbol != (c1_symbol *)0x0) && ((sym->flags3 & 8) == 0)) {
      dep_head_2 = (g_init_symbol->tail).data.dependents;
      dep_cell = arena_alloc(g_arenas,8);
      *dep_cell = sym;
      dep_cell[1] = dep_head_2;
      (g_init_symbol->tail).data.dependents = dep_cell;
      return;
    }
  }
  else if ((g_current_function != sym) && ((sym->flags3 & 8) == 0)) {
    if ((g_init_symbol != (c1_symbol *)0x0) && ((g_init_symbol->flags3 & 8) == 0)) {
      sym_note_reference_from_function(g_current_function,g_init_symbol,sym);
      return;
    }
    dep_head = (void *)((g_current_function->tail).fn.record)->unk14;
    dep_cell_2 = arena_alloc(g_arenas,8);
    *dep_cell_2 = sym;
    dep_cell_2[1] = dep_head;
    ((g_current_function->tail).fn.record)->unk14 = (c1_u32)dep_cell_2;
    return;
  }
  return;
}

