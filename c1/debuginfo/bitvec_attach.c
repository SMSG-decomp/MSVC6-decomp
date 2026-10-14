char __thiscall bitvec_attach(fe_bitvec *bitvec,int nbits,c1_u8 *bits)

{
  bitvec->bits = bits;
  bitvec->nbits = nbits;
  bitvec->owns_bits = '\0';
  bitvec->iter_bit = 0;
  bitvec->iter_byte = 0;
  bitvec->nbytes = (nbits >> 3) + 5U & 0xfffffffc;
  return '\x01';
}

