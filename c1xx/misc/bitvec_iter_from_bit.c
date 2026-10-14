void __fastcall bitvec_iter_from_bit(int bit,c1xx_bitvec *vec)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = bit >> 3;
  vec->iter_byte = iVar2;
  bVar1 = ~(('\x01' << ((byte)bit & 7)) - 1U) & vec->bits[iVar2];
  vec->iter_bits = bVar1;
  if (bVar1 == 0) {
    vec->iter_byte = iVar2 + 1;
  }
  bitvec_iter_scan_to_set_bit(vec);
  return;
}

