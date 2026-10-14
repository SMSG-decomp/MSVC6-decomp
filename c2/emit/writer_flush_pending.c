void writer_flush_pending(void)

{
  for (; g_referenced_symbol_list != (c2_list_cell *)0x0;
      g_referenced_symbol_list = g_referenced_symbol_list->next) {
    (*g_hook_emit_symbol_once)((g_referenced_symbol_list->u04).fe);
  }
  return;
}

