uint32_t * __fastcall bitvec_set(c2_bitvec *v,uint32_t n)

{
  uint *puVar1;
  
  puVar1 = v->words + (n >> 5);
  *puVar1 = *puVar1 | 1 << ((byte)n & 0x1f);
  return puVar1;
}

