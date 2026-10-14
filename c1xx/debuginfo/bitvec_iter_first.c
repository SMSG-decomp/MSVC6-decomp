char __fastcall bitvec_iter_first(c1xx_bitvec *bv)

{
  c1_u8 cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bv->iter_bit = 0;
  bv->iter_byte = 0;
  bv->iter_bits = *bv->bits;
  if (bv->iter_bits == '\0') {
    iVar2 = bv->iter_byte;
    iVar3 = bv->nbytes;
    iVar4 = iVar2 - iVar3;
    if (iVar2 < iVar3) {
      do {
        cVar1 = bv->bits[bv->iter_byte];
        bv->iter_bits = cVar1;
        if (cVar1 != '\0') break;
        iVar2 = bv->iter_byte + 1;
        bv->iter_byte = iVar2;
      } while (iVar2 < iVar3);
      iVar2 = bv->iter_byte;
      iVar4 = iVar2 - iVar3;
    }
    if (SBORROW4(iVar2,iVar3) == iVar4 < 0) {
      bv->iter_bit = bv->nbits + 1;
      return '\0';
    }
  }
  iVar3 = (uint)g_lowest_set_bit_table[bv->iter_bits] + bv->iter_byte * 8;
  bv->iter_bit = iVar3;
  return iVar3 <= bv->nbits;
}

