int basic_number_variables(void)

{
  int count;
  c2_symbol *sym;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_cursor;
  
  count = 0;
  chunk = g_symbol_chunks;
  do {
    if (chunk == (c2_symbol_chunk *)0x0) {
      return (int)(c2_copy_link *)count;
    }
    chunk_cursor = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_cursor; sym = sym + 1) {
      if (sym->cls != '\x10') {
        if (sym->storage == sym) {
          switch(sym->cls) {
          case '\x04':
          case '\x05':
          case '\a':
          case '\b':
            count = (int)&((c2_copy_link *)count)->next_of_source + 1;
            (sym->u34).source_links = (c2_copy_link *)count;
            goto LAB_10794df3;
          }
        }
        (sym->u34).refs = 0;
      }
LAB_10794df3:
    }
    chunk = chunk->next;
  } while( true );
}

