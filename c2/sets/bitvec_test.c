int __fastcall bitvec_test(c2_bitvec *v,uint32_t n)

{
  return (uint)((1 << ((byte)n & 0x1f) & v->words[n >> 5]) != 0);
}

