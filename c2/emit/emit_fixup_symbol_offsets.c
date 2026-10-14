void emit_fixup_symbol_offsets(void)

{
  c2_symbol *pcVar1;
  c2_symbol *sym;
  int32_t base_offset;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_cursor;
  c2_symbol *part;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_cursor = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_cursor; sym = sym + 1) {
      if (sym->cls != '\x10') {
        switch(sym->cls) {
        case '\x03':
          if ((sym->storage == sym) && ((sym->flags5 & 0x20) != 0)) {
            part = (sym->u28).free_next;
            for (pcVar1 = sym; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
              pcVar1->offset = (int)&part->fe + pcVar1->offset;
            }
          }
          break;
        case '\x04':
          if (sym->storage == sym) {
            base_offset = sym->fe->offset;
            for (part = sym; part != (c2_symbol *)0x0; part = part->part_next) {
              part->offset = part->offset + base_offset;
            }
          }
          break;
        case '\x05':
          if (sym->storage == sym) {
            base_offset = sym->fe->offset;
            for (part = sym; part != (c2_symbol *)0x0; part = part->part_next) {
              part->offset = part->offset + base_offset;
            }
          }
          break;
        case '\a':
        case '\b':
          if (sym->storage == sym) {
            base_offset = sym->fe->offset;
            for (part = sym; part != (c2_symbol *)0x0; part = part->part_next) {
              part->offset = part->offset + base_offset;
            }
          }
        }
      }
    }
  }
  return;
}

