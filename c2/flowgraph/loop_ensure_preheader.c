uint32_t __fastcall loop_ensure_preheader(c2_loop *loop,c2_function *fn)

{
  c2_block *to;
  c2_block *b;
  uint uVar1;
  c2_block *to_00;
  
  if (loop == (c2_loop *)0x0) {
    return 0;
  }
  if ((loop->flags & 1) != 0) {
    return 0;
  }
  to = loop->first;
  b = to->prev;
  if (b->next != to) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\lg.c",0x3e4);
  }
  if ((b->head->next == b->end) && (b->prev->loop == loop->parent)) {
    loop->guard = b->prev;
    uVar1 = b->flags;
    loop->preheader = b;
    b->flags = uVar1 | 0x8000000;
    return 0;
  }
  to_00 = block_split_before(fn,b,to->head);
  to_00->loop = loop->parent;
  flow_edge_delete_to(b,to,fn);
  cfg_add_edge(fn,b,to_00);
  cfg_add_edge(fn,to_00,to);
  uVar1 = to_00->flags;
  loop->preheader = to_00;
  loop->guard = b;
  to_00->flags = uVar1 | 0x8000000;
  return 1;
}

