char __fastcall bitvec_iter_first(fe_bitvec *iter)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iter->iter_bit = 0;
  iter->iter_byte = 0;
  iter->iter_bits = *iter->bits;
  if (iter->iter_bits == '\0') {
    iVar2 = iter->iter_byte;
    iVar3 = iter->nbytes;
    iVar4 = iVar2 - iVar3;
    if (iVar2 < iVar3) {
      do {
        uVar1 = iter->bits[iter->iter_byte];
        iter->iter_bits = uVar1;
        if (uVar1 != '\0') break;
        iVar2 = iter->iter_byte + 1;
        iter->iter_byte = iVar2;
      } while (iVar2 < iVar3);
      iVar2 = iter->iter_byte;
      iVar4 = iVar2 - iVar3;
    }
    if (SBORROW4(iVar2,iVar3) == iVar4 < 0) {
      iter->iter_bit = iter->nbits + 1;
      return '\0';
    }
  }
  iVar3 = (uint)g_lowest_set_bit_table[iter->iter_bits] + iter->iter_byte * 8;
  iter->iter_bit = iVar3;
  return iVar3 <= iter->nbits;
}

