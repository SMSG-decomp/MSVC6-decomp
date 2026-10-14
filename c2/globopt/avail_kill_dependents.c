void __fastcall avail_kill_dependents(c2_symbol *s,c2_symbol *parent)

{
  c2_symbol *parent_00;
  c2_symbol *s_00;
  
  if (s->visit_stamp != g_tuple_visit_count) {
    if (s->dependents != (c2_bitset *)0x0) {
      bitset_andnot(g_cur_avail_set,s->dependents);
      s->visit_stamp = g_tuple_visit_count;
    }
    parent_00 = s->storage;
    s_00 = parent_00;
    if (parent_00 != parent) {
      for (; s_00 != (c2_symbol *)0x0; s_00 = s_00->part_next) {
        if (s_00 != s) {
          if ((s_00->offset < s->size + s->offset) && (s->offset < s_00->size + s_00->offset)) {
            avail_kill_dependents(s_00,parent_00);
          }
        }
      }
    }
  }
  return;
}

