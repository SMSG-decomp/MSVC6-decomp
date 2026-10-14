void __cdecl sym_mark_enclosing_scopes(c1_symbol *sym)

{
  c1_symbol *sym_00;
  
  for (sym_00 = g_scope_vector->entries[(short)sym->scope_index]; sym_00 != (c1_symbol *)0x0;
      sym_00 = g_scope_vector->entries[(short)sym_00->scope_index]) {
    sym_00->flags2 = sym_00->flags2 & 0xf7;
    if (((((sym_00->kind & 0x1f) == 4) && ((((sym_00->detail).cls)->flags3e & 1) != 0)) &&
        ((((sym_00->detail).cls)->flags3f & 1) == 0)) &&
       ((tmpl_work_queue_add(sym_00,(int *)0x0), (sym->flags2 & 4) == 0 && ((sym->flags3 & 1) == 0))
       )) {
      (*g_idb->vtbl->idb_note_first_use)(g_idb);
    }
  }
  return;
}

