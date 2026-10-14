void __fastcall globdf_kill_dependents_tree(c2_symbol *s,c2_symbol *parent)

{
  c2_bitset *src;
  c2_symbol *parent_00;
  c2_symbol *s_00;
  
  if (s->visit_stamp != g_tuple_visit_count) {
    src = s->dependents;
    if (src != (c2_bitset *)0x0) {
      bitset_or(g_df_block_expr_killed,src);
      bitset_or(g_globdf_block_kill,src);
      bitset_andnot(g_globdf_block_gen,src);
      s->visit_stamp = g_tuple_visit_count;
    }
    parent_00 = s->storage;
    s_00 = parent_00;
    if (parent_00 != parent) {
      for (; s_00 != (c2_symbol *)0x0; s_00 = s_00->part_next) {
        if (s_00 != s) {
          if ((s_00->offset < s->size + s->offset) && (s->offset < s_00->size + s_00->offset)) {
            globdf_kill_dependents_tree(s_00,parent_00);
          }
        }
      }
    }
  }
  return;
}

