int __fastcall free_live_range(c2_live_range *lr,int unlink_from_queue)

{
  int iVar1;
  uint bucket;
  c2_live_range *chain;
  c2_live_range **link;
  uint32_t saved_id;
  
  bucket = lr->id;
  bitset_free(lr->allowed);
  if ((unlink_from_queue != 0) && (g_colour_queue != (c2_live_range *)0x0)) {
    g_colour_queue = colour_queue_unlink(lr,g_colour_queue);
  }
  bucket = bucket & 0x3ff;
  chain = g_live_range_hash[bucket];
  link = g_live_range_hash + bucket;
  while( true ) {
    if (chain == (c2_live_range *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0x15f8);
    }
    if (chain == lr) break;
    link = &chain->hash_next;
    chain = chain->hash_next;
  }
  saved_id = lr->id;
  *link = lr->hash_next;
  chain = lr;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    chain->sym = (c2_symbol *)0x0;
    chain = (c2_live_range *)&chain->kind;
  }
  chain = lr;
  lr->hash_next = g_live_range_free_list;
  g_live_range_free_list = chain;
  lr->id = saved_id;
  return 0;
}

