void __fastcall restore_temp_destinations(c2_function *fn)

{
  c2_cfg *pcVar1;
  c2_block *pcVar2;
  c2_bitset *dst;
  c2_bitset *bs2;
  c2_bitset *bs;
  c2_symbol *sym;
  c2_tuple *t;
  c2_tuple *next_t;
  c2_symbol_chunk *chunk;
  c2_symbol *chunk_limit;
  
  pcVar1 = fn->cfg;
  for (chunk = g_symbol_chunks; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    chunk_limit = chunk->cursor;
    for (sym = chunk->syms; sym < chunk_limit; sym = sym + 1) {
      if (sym->cls != '\x10') {
        (sym->u30).globopt.live = '\0';
        (sym->u30).globopt.killed = '\0';
        sym->defs = (c2_list_cell *)0x0;
        sym->uses = (c2_list_cell *)0x0;
      }
    }
  }
  g_dead_dst_overlap_live = 0;
  next_t = (c2_tuple *)fn;
  dst = bitset_new(6);
  bs2 = bitset_new(6);
  bs = bitset_new(6);
  for (pcVar2 = pcVar1->last; pcVar2 != (c2_block *)0x0; pcVar2 = pcVar2->prev) {
    bitset_copy(dst,pcVar2->ue);
    bitset_clear_all(bs);
    t = pcVar2->end->prev;
    if (t != pcVar2->head) {
      do {
        next_t = t->prev;
        if (((t->flags & 1) != 0) && (t->kind != '\x15')) {
          restore_temp_destinations_visit(t,dst,bs2,bs,&next_t);
        }
        t = next_t;
      } while (next_t != pcVar2->head);
    }
  }
  return;
}

