void __fastcall compute_block_expression_local_sets(c2_block *b)

{
  c2_tuple *t;
  
  g_globdf_block_gen = b->live_out;
  g_globdf_block_kill = b->live;
  g_df_block_expr_killed = b->set4c;
  bitset_clear_all(g_globdf_block_gen);
  bitset_clear_all(g_globdf_block_kill);
  bitset_clear_all(g_df_block_expr_killed);
  t = b->head->next;
  if (t != b->end) {
    do {
      if ((t->flags & 1) != 0) {
        globdf_expr_tuple_transfer(t);
      }
      t = t->next;
    } while (t != b->end);
  }
  return;
}

