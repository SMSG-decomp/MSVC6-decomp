c2_block * __fastcall block_split_before(c2_function *fn,c2_block *b,c2_tuple *at)

{
  c2_tuple *t;
  c2_block *pcVar1;
  
  t = tuple_new_block_boundary();
  tuple_insert_before(at,t);
  pcVar1 = block_new(fn,b->next,t,b->end);
  pcVar1->loop_depth = b->loop_depth;
  pcVar1->eh_state = b->eh_state;
  if (at->kind == '\x1a') {
    (at->u14).block = pcVar1;
  }
  return pcVar1;
}

