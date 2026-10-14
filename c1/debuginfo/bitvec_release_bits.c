c1_u8 * __fastcall bitvec_release_bits(fe_bitvec *bitvec)

{
  bitvec->owns_bits = '\0';
  return bitvec->bits;
}

