int __fastcall dbcheck_push_def(c2_symbol *sym)

{
  c2_symbol_cell *cell;
  
  cell = arena_alloc(4,8);
  cell->sym = sym;
  cell->next = g_dbcheck_pending_defs;
  g_dbcheck_pending_defs = cell;
  return 1;
}

