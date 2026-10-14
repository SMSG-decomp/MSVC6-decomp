c2_block * __fastcall block_new(c2_function *fn,c2_block *before,c2_tuple *boundary,c2_tuple *end)

{
  c2_block *pcVar1;
  
  pcVar1 = cfg_block_insert_before(fn->cfg,before);
  pcVar1->end = end;
  pcVar1->head = boundary;
  pcVar1->rpo = -1;
  pcVar1->loop_depth = 0;
  pcVar1->eh_state = -1;
  (boundary->u14).block = pcVar1;
  if (pcVar1->prev != (c2_block *)0x0) {
    pcVar1->prev->end = boundary;
  }
  return pcVar1;
}

