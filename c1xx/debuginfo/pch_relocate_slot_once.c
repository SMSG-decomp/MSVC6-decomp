char __thiscall pch_relocate_slot_once(void *pch_image,uint *slot)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  
  iVar1 = *(int *)(*(int *)((int)pch_image + 0x40) + ((uint)slot >> 0x10) * 4);
  if ((iVar1 != 0) && (slot < *(uint **)(iVar1 + 0x48))) {
    bVar2 = pch_block_is_visited
                      (*(c1xx_bitvec **)(iVar1 + 0x3c),(int)slot - *(int *)(iVar1 + 0x28) >> 2);
    if (bVar2 == 0) {
      pch_block_mark_visited
                (*(c1xx_bitvec **)(iVar1 + 0x3c),(int)slot - *(int *)(iVar1 + 0x28) >> 2);
      cVar3 = pch_relocate_pointer(pch_image,slot);
      return cVar3;
    }
  }
  return '\0';
}

