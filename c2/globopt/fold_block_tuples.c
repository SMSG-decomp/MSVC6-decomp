void __fastcall fold_block_tuples(c2_block *block,c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  
  pcVar1 = block->end;
  pcVar2 = block->head->next;
  while (t = pcVar2, t != pcVar1) {
    g_next_tuple_cursor = t->next;
    pcVar2 = g_next_tuple_cursor;
    if (t->kind == '\f') {
      simplify_tuple(t,block,fn);
      pcVar2 = g_next_tuple_cursor;
    }
  }
  return;
}

