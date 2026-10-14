char __fastcall bitvec_iter_next(fe_bitvec *iter)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = iter->iter_bit + 1;
  iter->iter_bit = iVar3;
  if (iter->nbits < iVar3) {
    return '\0';
  }
  iVar4 = iVar3 >> 3;
  iter->iter_byte = iVar4;
  bVar1 = ~(('\x01' << ((byte)iVar3 & 7)) - 1U) & iter->bits[iVar4];
  iter->iter_bits = bVar1;
  if (bVar1 == 0) {
    iter->iter_byte = iVar4 + 1;
  }
  uVar2 = bitvec_iter_scan_to_set_bit((int)iter);
  return (char)uVar2;
}

