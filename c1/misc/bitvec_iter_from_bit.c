void __fastcall bitvec_iter_from_bit(int bit,int iter)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = bit >> 3;
  *(int *)(iter + 0x18) = iVar2;
  bVar1 = ~(('\x01' << ((byte)bit & 7)) - 1U) & *(byte *)(*(int *)(iter + 0xc) + iVar2);
  *(byte *)(iter + 0x1c) = bVar1;
  if (bVar1 == 0) {
    *(int *)(iter + 0x18) = iVar2 + 1;
  }
  bitvec_iter_scan_to_set_bit(iter);
  return;
}

