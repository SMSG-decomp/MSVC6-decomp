int __fastcall dbcheck_pop_pending_def(c2_symbol *sym)

{
  c2_symbol_cell *cell;
  c2_symbol_cell *next_cell;
  c2_symbol_cell *prev_cell;
  
  if (g_dbcheck_pending_defs != (c2_symbol_cell *)0x0) {
    if ((g_dbcheck_pending_defs->sym->storage == sym->storage) &&
       (g_dbcheck_pending_defs->sym->def == sym->def)) {
      g_dbcheck_pending_defs = g_dbcheck_pending_defs->next;
      return 1;
    }
    next_cell = g_dbcheck_pending_defs->next;
    prev_cell = g_dbcheck_pending_defs;
    while (cell = next_cell, cell != (c2_symbol_cell *)0x0) {
      if ((cell->sym->storage == sym->storage) && (cell->sym->def == sym->def)) {
        prev_cell->next = prev_cell->next->next;
        return 1;
      }
      prev_cell = cell;
      next_cell = cell->next;
    }
  }
  return 0;
}

