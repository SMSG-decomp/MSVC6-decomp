fe_bitvec * __fastcall bitvec_init_empty(fe_bitvec *bitvec)

{
  bitvec->nbits = 0;
  bitvec->bits = (uchar *)0x0;
  bitvec->iter_bit = 0;
  bitvec->nbytes = 0;
  return bitvec;
}

