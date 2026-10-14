c2_live_range * __fastcall live_range_from_id(uint32_t id)

{
  c2_live_range *pcVar1;
  
  pcVar1 = g_live_range_hash[id & 0x3ff];
  while( true ) {
    if (pcVar1 == (c2_live_range *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0x1607);
    }
    if (pcVar1->id == id) break;
    pcVar1 = pcVar1->hash_next;
  }
  return pcVar1;
}

