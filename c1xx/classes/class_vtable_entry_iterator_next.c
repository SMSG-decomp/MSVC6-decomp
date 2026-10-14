uint __cdecl class_vtable_entry_iterator_next(int *iter)

{
  int iVar1;
  int iVar2;
  uint3 uVar3;
  
  iVar1 = iter[1];
  uVar3 = (uint3)((uint)iter >> 8);
  if (iVar1 < *(int *)(*iter + 0x10)) {
    iVar2 = *(int *)(iVar1 * 0x10 + *(int *)(*iter + 0x18));
    iter[1] = iVar1 + 1;
    iter[2] = iVar2;
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}

