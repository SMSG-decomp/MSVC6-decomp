int __cdecl eh_count_usable_catchable_types(c1_vector *catchables)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  iVar1 = 0;
  if ((catchables != (c1_vector *)0x0) && (catchables->count != 0)) {
    sVar3 = 0;
    while (iVar2 = (int)sVar3, iVar2 < (int)(uint)catchables->count) {
      sVar3 = sVar3 + 1;
      if ((*(uint *)((int)catchables->data[iVar2] + 4) & 20000) == 0) {
        iVar1 = iVar1 + 1;
      }
    }
    return iVar1;
  }
  return 0;
}

