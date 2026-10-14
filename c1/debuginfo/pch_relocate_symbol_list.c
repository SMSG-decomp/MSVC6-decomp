void __fastcall pch_relocate_symbol_list(void *cell)

{
  int iVar1;
  char cVar2;
  
  do {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint)cell);
      pch_relocate_symbol((byte *)((int)cell + -8));
      cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)((int)cell + 4));
      if (cVar2 == '\0') {
        return;
      }
      cell = *(void **)((int)cell + 4);
    } while ((*(byte *)((int)cell + -8) & 0x1f) != 4);
    pch_relocate_symbol_list(cell);
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)((int)cell + 0x2c));
    if (cVar2 == '\0') {
      return;
    }
    iVar1 = *(int *)((int)cell + 0x2c);
    pch_relocate_slot_once(&g_pch_image,iVar1 + 8);
    cVar2 = pch_relocate_slot_once(&g_pch_image,iVar1 + 4U);
    if (cVar2 == '\0') {
      return;
    }
    cell = *(void **)(iVar1 + 4U);
  } while ((*(byte *)((int)cell + -8) & 0x1f) != 4);
  pch_relocate_tag_symbol_list(*(void **)(iVar1 + 4));
  return;
}

