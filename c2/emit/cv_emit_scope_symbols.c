void __fastcall cv_emit_scope_symbols(c2_fe_symbol *fn_sym)

{
  short base_level;
  bool block_opened;
  c2_list_cell *cell;
  
  if (g_cv_scope_cursor != (c2_cv_scope *)0x0) {
    base_level = g_cv_scope_cursor->level;
    do {
      if (g_cv_scope_cursor->level < base_level) {
        return;
      }
      if (((g_cv_scope_cursor->symbols == (c2_list_cell *)0x0) || (g_cv_scope_cursor->level < 3)) ||
         (g_opt_global != 0)) {
        block_opened = false;
      }
      else {
        block_opened = true;
        cv_emit_block32_symbol
                  (fn_sym,g_cv_scope_cursor->start,g_cv_scope_cursor->end - g_cv_scope_cursor->start
                  );
      }
      for (cell = g_cv_scope_cursor->symbols; cell != (c2_list_cell *)0x0; cell = cell->next) {
        emit_symbol_definition_edx0((cell->u04).fe);
      }
      g_cv_scope_cursor = g_cv_scope_cursor->next;
      if ((g_cv_scope_cursor != (c2_cv_scope *)0x0) && (base_level < g_cv_scope_cursor->level)) {
        cv_emit_scope_symbols(fn_sym);
      }
      if (block_opened) {
        cv_emit_end_symbol();
      }
    } while (g_cv_scope_cursor != (c2_cv_scope *)0x0);
  }
  return;
}

