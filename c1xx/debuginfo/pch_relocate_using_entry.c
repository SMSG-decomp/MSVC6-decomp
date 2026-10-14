void __cdecl pch_relocate_using_entry(int value)

{
  uint *slot;
  char cVar1;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)(value + 8));
  cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(value + 4));
  if (cVar1 != '\0') {
    slot = *(uint **)(value + 4);
    pch_relocate_slot_once(&g_pch_image,slot);
    pch_relocate_symbol((byte *)(slot + -2));
    pch_relocate_slot_once(&g_pch_image,slot + 7);
    cVar1 = pch_relocate_slot_once(&g_pch_image,slot + 1);
    if (cVar1 != '\0') {
      pch_relocate_symbol_list_simple(slot[1]);
    }
  }
  return;
}

