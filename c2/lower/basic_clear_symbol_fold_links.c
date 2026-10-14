void basic_clear_symbol_fold_links(void)

{
  c2_symbol *sym;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_cursor;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_cursor = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_cursor; sym = sym + 1) {
      if (sym->cls != '\x10') {
        sym->defs = (c2_list_cell *)0x0;
      }
    }
  }
  return;
}

