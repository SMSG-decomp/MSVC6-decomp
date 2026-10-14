void __fastcall pch_relocate_symbol_list_simple(int element)

{
  char cVar1;
  
  while( true ) {
    pch_relocate_slot_once(&g_pch_image,element);
    pch_relocate_symbol((byte *)(element - 8));
    pch_relocate_slot_once(&g_pch_image,element + 0x1c);
    cVar1 = pch_relocate_slot_once(&g_pch_image,element + 4U);
    if (cVar1 == '\0') break;
    element = *(uint *)(element + 4U);
  }
  return;
}

