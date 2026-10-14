int __fastcall ovl_first_live_candidate(int ctx)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(ctx + 0x18);
  bVar1 = *(byte *)(iVar2 + 0x3c);
  while ((bVar1 & 0x80) != 0) {
    iVar2 = *(int *)(iVar2 + 0x1c);
    bVar1 = *(byte *)(iVar2 + 0x3c);
  }
  return iVar2;
}

