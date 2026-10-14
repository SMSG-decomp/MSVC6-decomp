int __cdecl number_trackable_locals(void)

{
  int local_count;
  c2_symbol *sym;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_end;
  c2_symbol *part;
  
  local_count = 0;
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_end = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_end; sym = sym + 1) {
      if ((sym->cls != '\x10') && (sym->storage == sym)) {
        part = sym;
        if ((sym->storage->fe == (c2_fe_symbol *)0x0) ||
           ((sym->fe->name == (char *)0x0 || (sym->cls != '\x04')))) {
          for (; part != (c2_symbol *)0x0; part = part->part_next) {
            (part->u30).order_prev = (c2_symbol *)0x0;
          }
        }
        else {
          for (; part != (c2_symbol *)0x0; part = part->part_next) {
            local_count = (int)&((c2_symbol *)local_count)->fe + 1;
            (part->u30).order_prev = (c2_symbol *)local_count;
          }
        }
      }
    }
  }
  return (int)(c2_symbol *)local_count;
}

