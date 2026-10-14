c1xx_bitvec * __fastcall bitvec_init_empty(c1xx_bitvec *bv)

{
  bv->nbits = 0;
  bv->bits = (c1_u8 *)0x0;
  bv->iter_bit = 0;
  bv->nbytes = 0;
  return bv;
}

