int __fastcall ovl_unique_candidate(int ctx)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = *(int *)(ctx + 0x18);
  iVar1 = 0;
  if (iVar2 != 0) {
    while (((*(byte *)(iVar2 + 0x3c) & 0x20) != 0 || (bVar3 = iVar1 == 0, iVar1 = iVar2, bVar3))) {
      iVar2 = *(int *)(iVar2 + 0x1c);
      if (iVar2 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

