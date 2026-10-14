void __fastcall recompute_loop_liveness(c2_loop *loop,uint32_t flags)

{
  c2_block *first;
  
  if ((flags & 2) != 0) {
    g_liveness_mode = 1;
  }
  clear_block_liveness_visited(loop->preheader,loop->last);
  if ((flags & 1) == 0) {
    first = loop->first;
  }
  else {
    first = loop->preheader;
  }
  liveness_dce_blocks(first,loop->last);
  g_liveness_mode = 0;
  return;
}

