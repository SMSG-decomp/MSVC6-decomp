void __fastcall pch_relocate_tag_symbol_list(void *cell)

{
  void *pvVar1;
  int iVar2;
  char cVar3;
  uint *slot;
  
  do {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint)cell);
      pch_relocate_symbol((byte *)((int)cell + -8));
      cVar3 = pch_relocate_slot_once(&g_pch_image,(int)cell + 4U);
      if (cVar3 != '\0') {
        pvVar1 = *(void **)((int)cell + 4U);
        if ((*(byte *)((int)pvVar1 + -8) & 0x1f) == 4) {
          pch_relocate_tag_symbol_list(pvVar1);
        }
        else {
          pch_relocate_symbol_list(pvVar1);
        }
      }
      cVar3 = pch_relocate_slot_once(&g_pch_image,(uint)((int)cell + 0x2c));
      if (cVar3 == '\0') {
        return;
      }
      iVar2 = *(int *)((int)cell + 0x2c);
      pch_relocate_slot_once(&g_pch_image,iVar2 + 8);
      slot = (uint *)(iVar2 + 4);
      cVar3 = pch_relocate_slot_once(&g_pch_image,(uint)slot);
      if (cVar3 == '\0') {
        return;
      }
      pvVar1 = (void *)*slot;
      cell = pvVar1;
    } while ((*(byte *)((int)pvVar1 - 8) & 0x1f) == 4);
    pch_relocate_slot_once(&g_pch_image,(uint)pvVar1);
    pch_relocate_symbol((byte *)((int)pvVar1 - 8));
    cVar3 = pch_relocate_slot_once(&g_pch_image,(int)pvVar1 + 4U);
    if (cVar3 == '\0') {
      return;
    }
    cell = *(void **)((int)pvVar1 + 4U);
  } while ((*(byte *)((int)cell + -8) & 0x1f) == 4);
  pch_relocate_symbol_list(*(void **)((int)pvVar1 + 4));
  return;
}

