uint __fastcall bitvec_iter_scan_to_set_bit(c1xx_bitvec *vec)

{
  c1_u8 cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (vec->iter_bits == '\0') {
    iVar2 = vec->iter_byte;
    iVar3 = vec->nbytes;
    iVar4 = iVar2 - iVar3;
    if (iVar2 < iVar3) {
      do {
        cVar1 = vec->bits[vec->iter_byte];
        vec->iter_bits = cVar1;
        if (cVar1 != '\0') break;
        iVar2 = vec->iter_byte + 1;
        vec->iter_byte = iVar2;
      } while (iVar2 < iVar3);
      iVar2 = vec->iter_byte;
      iVar4 = iVar2 - iVar3;
    }
    if (SBORROW4(iVar2,iVar3) == iVar4 < 0) {
      uVar5 = vec->nbits + 1;
      vec->iter_bit = uVar5;
      return uVar5 & 0xffffff00;
    }
  }
  iVar3 = (uint)g_lowest_set_bit_table[vec->iter_bits] + vec->iter_byte * 8;
  vec->iter_bit = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),iVar3 <= vec->nbits);
}

