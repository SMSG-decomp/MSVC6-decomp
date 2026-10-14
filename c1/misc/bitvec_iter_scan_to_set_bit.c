uint __fastcall bitvec_iter_scan_to_set_bit(int iter)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(iter + 0x1c) == '\0') {
    iVar2 = *(int *)(iter + 0x18);
    iVar3 = *(int *)(iter + 0x10);
    iVar4 = iVar2 - iVar3;
    if (iVar2 < iVar3) {
      do {
        cVar1 = *(char *)(*(int *)(iter + 0xc) + *(int *)(iter + 0x18));
        *(char *)(iter + 0x1c) = cVar1;
        if (cVar1 != '\0') break;
        iVar2 = *(int *)(iter + 0x18) + 1;
        *(int *)(iter + 0x18) = iVar2;
      } while (iVar2 < iVar3);
      iVar2 = *(int *)(iter + 0x18);
      iVar4 = iVar2 - iVar3;
    }
    if (SBORROW4(iVar2,iVar3) == iVar4 < 0) {
      uVar5 = *(int *)(iter + 8) + 1;
      *(uint *)(iter + 0x14) = uVar5;
      return uVar5 & 0xffffff00;
    }
  }
  iVar3 = (uint)g_lowest_set_bit_table[*(byte *)(iter + 0x1c)] + *(int *)(iter + 0x18) * 8;
  *(int *)(iter + 0x14) = iVar3;
  return CONCAT31((int3)((uint)iVar3 >> 8),iVar3 <= *(int *)(iter + 8));
}

