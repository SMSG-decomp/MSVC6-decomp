char __thiscall pch_relocate_pointer(void *pch_image,uint *slot)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *slot;
  if (((uVar1 != 0) &&
      (iVar2 = *(int *)(*(int *)((int)pch_image + 0x3c) + (uVar1 >> 0x10) * 4), iVar2 != 0)) &&
     (uVar1 < *(uint *)(iVar2 + 0x44))) {
    if (*(int *)(iVar2 + 0xc) == 5) {
      *slot = *(int *)(iVar2 + 0x40) + uVar1;
    }
    return '\x01';
  }
  return '\0';
}

