int __cdecl type_set_find(short *set,int value,int *index)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  
  iVar4 = 0;
  uVar6 = (ushort)value & 0x3fff;
  iVar5 = (int)*set;
  iVar3 = iVar5;
  if (0 < iVar5) {
    do {
      iVar1 = iVar3 + iVar4 >> 1;
      if ((set[iVar1 * 2 + 2] & 0x3fffU) < uVar6) {
        iVar4 = iVar1 + 1;
        iVar1 = iVar3;
      }
      iVar3 = iVar1;
    } while (iVar4 < iVar1);
  }
  iVar3 = iVar4;
  if (iVar4 < iVar5) {
    puVar2 = (ushort *)(set + iVar4 * 2 + 2);
    iVar1 = iVar4;
    do {
      iVar3 = iVar4;
      if (((*puVar2 & 0x3fff) != uVar6) || (iVar3 = iVar1, *(int *)puVar2 == value)) break;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 2;
      iVar3 = iVar4;
    } while (iVar1 < iVar5);
  }
  if (index != (int *)0x0) {
    *index = iVar3;
  }
  if ((iVar3 < *set) && (*(int *)(set + iVar3 * 2 + 2) == value)) {
    return 1;
  }
  return 0;
}

