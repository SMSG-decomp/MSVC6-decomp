void __fastcall pch_relocate_symbol_list_simple(int entry)

{
  char cVar1;
  
  while( true ) {
    pch_relocate_slot_once(&g_pch_image,(uint *)entry);
    pch_relocate_symbol((byte *)(entry + -8));
    pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x1c));
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 4));
    if (cVar1 == '\0') break;
    entry = *(uint *)(entry + 4);
  }
  return;
}

