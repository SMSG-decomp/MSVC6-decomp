void __fastcall globopt_reset_symbol_state(c2_function *fn)

{
  c2_tuple *pcVar1;
  int iVar2;
  c2_symbol *sym;
  uint32_t *clear_cursor;
  c2_symbol_chunk *chunk;
  
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    sym = chunk->syms;
    if (sym < chunk->cursor) {
      do {
        if (sym->cls != '\x10') {
          clear_cursor = (uint32_t *)&sym->order_next;
          for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
            *clear_cursor = 0;
            clear_cursor = clear_cursor + 1;
          }
          if (sym->cls != '\t') {
            (sym->u28).free_next = (c2_symbol *)0x0;
          }
        }
        sym = sym + 1;
      } while (sym < chunk->cursor);
    }
  }
  g_exit_used_symbols = g_global_symbol_ids;
  g_loop_local_gen = bitset_new(0xd);
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    pcVar1->flags12 = '\0';
    pcVar1->flags13 = '\0';
  }
  g_tuple_visit_count = 0;
  return;
}

