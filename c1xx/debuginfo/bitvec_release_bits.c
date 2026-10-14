c1_u8 * __fastcall bitvec_release_bits(c1xx_bitvec *bv)

{
  bv->owns_bits = '\0';
  return bv->bits;
}

