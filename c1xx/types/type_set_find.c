int __cdecl type_set_find(short *set,int value,int *index_out)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  
  iVar4 = 0;
  uVar6 = (ushort)value & 0x3fff;
  iVar5 = (int)*set;
  iVar2 = iVar5;
  if (0 < iVar5) {
    do {
      iVar3 = iVar2 + iVar4 >> 1;
      if ((set[iVar3 * 2 + 2] & 0x3fffU) < uVar6) {
        iVar4 = iVar3 + 1;
        iVar3 = iVar2;
      }
      iVar2 = iVar3;
    } while (iVar4 < iVar3);
  }
  iVar2 = iVar4;
  if (iVar4 < iVar5) {
    puVar1 = (ushort *)(set + iVar4 * 2 + 2);
    iVar3 = iVar4;
    do {
      iVar2 = iVar4;
      if (((*puVar1 & 0x3fff) != uVar6) || (iVar2 = iVar3, *(int *)puVar1 == value)) break;
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 2;
      iVar2 = iVar4;
    } while (iVar3 < iVar5);
  }
  if (index_out != (int *)0x0) {
    *index_out = iVar2;
  }
  if ((iVar2 < *set) && (*(int *)(set + iVar2 * 2 + 2) == value)) {
    return 1;
  }
  return 0;
}

