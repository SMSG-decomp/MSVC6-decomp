void __fastcall cleanup_preheader_after_sr(c2_loop *loop,c2_function *fn)

{
  c2_block *pcVar1;
  c2_tuple *t;
  
  pcVar1 = loop->preheader;
  g_cur_avail_set = pcVar1->set50;
  t = pcVar1->head->next;
  if (t != pcVar1->end) {
    do {
      if ((t->flags & 1) != 0) {
        cse_replace_operands(t);
        g_pending_tuples = (c2_list_cell *)0x0;
      }
      t = t->next;
    } while (t != pcVar1->end);
  }
  simplify_preheader_tuples(pcVar1->head,(int *)pcVar1->end,fn);
  return;
}

