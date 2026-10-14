void __fastcall pass_sizeopt(c2_function *fn)

{
  c2_block *block;
  int iVar1;
  c2_symbol *sym;
  uint32_t *width_facts;
  uint32_t *clear_cursor;
  c2_symbol_chunk *chunk;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    sym = chunk->syms;
    if (sym < chunk->cursor) {
      width_facts = (uint32_t *)&chunk->syms[0].order_next;
      do {
        if ((char)width_facts[-10] != '\x10') {
          clear_cursor = width_facts;
          for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
            *clear_cursor = 0;
            clear_cursor = clear_cursor + 1;
          }
        }
        sym = sym + 1;
        width_facts = width_facts + 0x15;
      } while (sym < chunk->cursor);
    }
  }
  for (block = fn->cfg->first; block != (c2_block *)0x0; block = block->next) {
    sizeopt_block(block);
  }
  return;
}

