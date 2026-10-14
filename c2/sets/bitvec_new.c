c2_bitvec * __fastcall bitvec_new(int arena,uint32_t nbits)

{
  c2_bitvec *pcVar1;
  c2_bitvec *vec;
  
  vec = (c2_bitvec *)g_bitset_free_head[arena];
  if (vec == (c2_bitvec *)0x0) {
    pcVar1 = arena_alloc(arena,0xc);
    pcVar1->words = (uint32_t *)0x0;
    pcVar1 = bitvec_init(pcVar1,arena,nbits);
    return pcVar1;
  }
  g_bitset_free_head[arena] = (c2_bitset *)vec->words;
  vec->words = (uint32_t *)0x0;
  pcVar1 = bitvec_init(vec,arena,nbits);
  return pcVar1;
}

