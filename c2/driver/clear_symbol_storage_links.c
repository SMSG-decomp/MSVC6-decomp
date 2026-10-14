void clear_symbol_storage_links(void)

{
  c2_symbol *sym;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_end;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_end = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_end; sym = sym + 1) {
      if ((sym->cls != '\x10') && (sym->fe != (c2_fe_symbol *)0x0)) {
        sym->fe->storage_sym = (c2_symbol *)0x0;
      }
    }
  }
  return;
}

