c2_bitset * __fastcall bitset_new(int arena)

{
  c2_bitset *pcVar1;
  
  pcVar1 = g_bitset_free_head[arena];
  if (pcVar1 == (c2_bitset *)0x0) {
    pcVar1 = arena_alloc(arena,0xc);
  }
  else {
    g_bitset_free_head[arena] = (c2_bitset *)pcVar1->chunks;
  }
  pcVar1->arena = (uint8_t)arena;
  pcVar1->chunks = (c2_bitset_chunk *)0x0;
  pcVar1->nbits = pcVar1->nbits & 0xff000000;
  return pcVar1;
}

