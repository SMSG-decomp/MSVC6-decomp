void __fastcall bitset_header_free(c2_bitvec *vec)

{
  byte bVar1;
  
  bVar1 = vec->arena;
  if (g_bitset_free_head[bVar1] == (c2_bitset *)0x0) {
    g_bitset_free_head[bVar1] = (c2_bitset *)vec;
  }
  else {
    g_bitset_free_tail[bVar1]->chunks = (c2_bitset_chunk *)vec;
  }
  g_bitset_free_tail[bVar1] = (c2_bitset *)vec;
  vec->words = (uint32_t *)0x0;
  vec->nbits = vec->nbits & 0xff000000;
  return;
}

