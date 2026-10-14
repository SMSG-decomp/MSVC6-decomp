void __fastcall create_web_live_ranges(c2_live_range **web_ranges)

{
  c2_bitset *bs;
  c2_live_range *pcVar1;
  int iVar2;
  c2_symbol **bucket;
  c2_symbol *sym;
  c2_ra_candidate *cand;
  c2_live_range *range;
  c2_symbol_chunk *chunk;
  c2_ra_web_cell *web;
  
  bucket = g_constant_symbol_hash;
  do {
    for (sym = *bucket; sym != (c2_symbol *)0x0; sym = sym->order_next) {
      cand = (sym->u30).ra;
      if ((int)cand->web < 1) {
        range = (cand->u0c).range;
        (cand->u0c).webs = (c2_ra_web_cell *)0x0;
        free_live_range(range,0);
        bitset_clear(g_class_candidates[0],range->id);
      }
    }
    bucket = bucket + 1;
    chunk = g_symbol_chunks;
  } while ((int)bucket < 0x1079d850);
  for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    sym = chunk->syms;
    if (sym < chunk->cursor) {
      do {
        if ((sym->cls != '\x10') && ((sym->u30).ra != (c2_ra_candidate *)0x0)) {
          for (web = (((sym->u30).ra)->u0c).webs; web != (c2_ra_web_cell *)0x0; web = web->next) {
            pcVar1 = new_live_range(sym);
            bs = web->defs;
            iVar2 = bitset_iter_next(bs);
            while (iVar2 != -1) {
              web_ranges[iVar2] = pcVar1;
              iVar2 = bitset_iter_next((c2_bitset *)0x0);
            }
            bitset_free(bs);
          }
        }
        sym = sym + 1;
      } while (sym < chunk->cursor);
    }
  }
  return;
}

