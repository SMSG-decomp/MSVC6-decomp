void __fastcall liveness_init_block_sets(c2_block *b)

{
  c2_bitset *bs;
  c2_tuple *t;
  
  g_df_block_def = b->set28;
  g_df_block_use = b->set24;
  g_df_block_part_def = b->kill;
  g_df_block_part_use = (b->avail_in).set;
  bitset_clear_all(g_df_block_use);
  bitset_clear_all(g_df_block_def);
  bitset_clear_all(g_df_block_part_def);
  bitset_clear_all(g_df_block_part_use);
  bitset_clear_all(b->de);
  bs = b->ue;
  bitset_clear_all(bs);
  bitset_clear_all((b->avail_out).set);
  bitset_clear_all(b->live_in);
  if (b->next == (c2_block *)0x0) {
    bitset_copy(bs,g_exit_used_symbols);
  }
  t = b->end->prev;
  if (t != b->head) {
    do {
      if ((t->flags & 1) != 0) {
        globdf_tuple_transfer(t);
      }
      t = t->prev;
    } while (t != b->head);
  }
  bitset_and(g_df_block_part_def,g_partial_overlap_syms);
  b->flags = b->flags | 0x4000000;
  return;
}

