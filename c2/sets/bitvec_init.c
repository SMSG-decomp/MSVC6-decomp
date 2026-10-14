c2_bitvec * __fastcall bitvec_init(c2_bitvec *vec,int arena,uint32_t nbits)

{
  uint32_t *puVar1;
  
  vec->words = (uint32_t *)0x0;
  vec->nbits = nbits & 0xffffff ^ vec->nbits & 0xff000000;
  puVar1 = arena_alloc(arena,(nbits + 0x1f >> 5) << 2);
  vec->words = puVar1;
  vec->arena = (uint8_t)arena;
  return vec;
}

