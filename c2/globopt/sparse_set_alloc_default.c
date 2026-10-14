c2_bitset * sparse_set_alloc_default(void)

{
  c2_bitset *pcVar1;
  
  if (g_bitset_free_head[6] == (c2_bitset *)0x0) {
    pcVar1 = arena_alloc(6,0xc);
  }
  else {
    pcVar1 = g_bitset_free_head[6];
    g_bitset_free_head[6] = (c2_bitset *)g_bitset_free_head[6]->chunks;
  }
  pcVar1->arena = '\x06';
  pcVar1->chunks = (c2_bitset_chunk *)0x0;
  pcVar1->nbits = pcVar1->nbits & 0xff000000;
  return pcVar1;
}

