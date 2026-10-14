void __fastcall bitvec_clear(c2_bitvec *v,uint32_t n)

{
  v->words[n >> 5] = v->words[n >> 5] & ~(1 << ((byte)n & 0x1f));
  return;
}

