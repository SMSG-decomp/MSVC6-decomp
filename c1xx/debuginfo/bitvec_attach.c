char __thiscall bitvec_attach(c1xx_bitvec *bv,int nbits,c1_u8 *bits)

{
  bv->bits = bits;
  bv->nbits = nbits;
  bv->owns_bits = '\0';
  bv->iter_bit = 0;
  bv->iter_byte = 0;
  bv->nbytes = (nbits >> 3) + 5U & 0xfffffffc;
  return '\x01';
}

