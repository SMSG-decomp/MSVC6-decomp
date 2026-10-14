void __thiscall scope_link_closed_block(void *scope,int block)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (block == 0) {
    return;
  }
  iVar2 = *(int *)((int)scope + 0x20c);
  if (iVar2 == 0) goto LAB_10618fcf;
  iVar3 = 0;
  do {
    iVar4 = iVar2;
    iVar1 = iVar4;
    if (*(byte *)(block + 8) < *(byte *)(iVar4 + 8)) goto joined_r0x10618fb0;
    iVar2 = *(int *)(iVar4 + 4);
    iVar3 = iVar4;
  } while (iVar2 != 0);
LAB_10618fc0:
  if (iVar4 != 0) {
    *(int *)(iVar4 + 4) = block;
    *(int *)(block + 4) = iVar2;
    return;
  }
LAB_10618fcf:
  *(int *)((int)scope + 0x20c) = block;
  *(int *)(block + 4) = iVar2;
  return;
joined_r0x10618fb0:
  while ((iVar4 = iVar3, iVar2 = iVar1, iVar2 != 0 && (*(int *)(iVar2 + 0xc) != block))) {
    iVar3 = iVar2;
    iVar1 = *(int *)(iVar2 + 4);
  }
  goto LAB_10618fc0;
}

