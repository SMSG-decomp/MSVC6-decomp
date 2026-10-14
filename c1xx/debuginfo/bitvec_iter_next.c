char __fastcall bitvec_iter_next(c1xx_bitvec *bv)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = bv->iter_bit + 1;
  bv->iter_bit = iVar3;
  if (bv->nbits < iVar3) {
    return '\0';
  }
  iVar4 = iVar3 >> 3;
  bv->iter_byte = iVar4;
  bVar1 = ~(('\x01' << ((byte)iVar3 & 7)) - 1U) & bv->bits[iVar4];
  bv->iter_bits = bVar1;
  if (bVar1 == 0) {
    bv->iter_byte = iVar4 + 1;
  }
  uVar2 = bitvec_iter_scan_to_set_bit(bv);
  return (char)uVar2;
}

