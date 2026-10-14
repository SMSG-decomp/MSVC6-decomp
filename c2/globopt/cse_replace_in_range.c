void __fastcall cse_replace_in_range(c2_tuple *first,c2_tuple **end,c2_loop *loop,c2_function *fn)

{
  c2_tuple *t;
  
  g_cur_avail_set = loop->preheader->set50;
  t = first;
  if (first != *end) {
    do {
      if ((t->flags & 1) != 0) {
        cse_replace_operands(t);
      }
      t = t->next;
    } while (t != *end);
  }
  simplify_preheader_tuples(first,(int *)end,fn);
  return;
}

