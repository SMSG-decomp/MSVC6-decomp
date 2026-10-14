void __cdecl conv_warn_different_bases(int op,byte *type,byte *type2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  
  if (((*type2 & 0x8f) != 0x83) || ((type2[2] & 8) == 0)) {
    bVar1 = type2[2];
    bVar5 = bVar1 & 0x18;
    bVar2 = type[2];
    bVar3 = bVar2 & 0x18;
    if (((((bVar2 & 8) != 0) || (((bVar1 & 8) != 0 && ((bVar2 & 8) != 0)))) && ((bVar1 & 8) != 0))
       && ((bVar5 != 8 && (bVar3 != 8)))) {
      if (bVar5 != bVar3) {
        diag_warning(1,0x7b);
        return;
      }
      if (bVar3 == 0x18) {
        iVar6 = *(int *)(type + 8);
      }
      else {
        iVar6 = 0;
      }
      if (bVar5 == 0x18) {
        iVar4 = *(int *)(type2 + 8);
      }
      else {
        iVar4 = 0;
      }
      if (iVar6 != iVar4) {
        diag_warning(1,0x77,iVar6,iVar4);
      }
    }
  }
  return;
}

