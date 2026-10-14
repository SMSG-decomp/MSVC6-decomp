void __fastcall pch_relocate_symbol_list_c(int entry)

{
  uint entry_00;
  char cVar1;
  byte bVar2;
  uint *slot;
  
  do {
    while( true ) {
      pch_relocate_slot_once(&g_pch_image,(uint *)entry);
      pch_relocate_symbol((byte *)(entry + -8));
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 4));
      if (cVar1 != '\0') {
        entry_00 = *(uint *)(entry + 4);
        if ((*(byte *)(entry_00 - 8) & 0x1f) == 4) {
          pch_relocate_symbol_list(entry_00);
          cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry_00 + 0x20));
          if (cVar1 != '\0') {
            pch_relocate_class_scope_list(*(uint *)(entry_00 + 0x20));
          }
        }
        else {
          bVar2 = *(byte *)(entry_00 - 8) & 0x1f;
          if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
            pch_relocate_symbol_list_c(entry_00);
          }
          else {
            pch_relocate_symbol_list(entry_00);
          }
        }
      }
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0xc));
      if (cVar1 == '\0') {
        return;
      }
      slot = *(uint **)(entry + 0xc);
      pch_relocate_slot_once(&g_pch_image,slot);
      pch_relocate_symbol((byte *)(slot + -2));
      cVar1 = pch_relocate_slot_once(&g_pch_image,slot + 1);
      if (cVar1 == '\0') {
        return;
      }
      entry = slot[1];
      if ((*(uint *)(entry + -8) & 0x1f) != 4) break;
      pch_relocate_symbol_list(entry);
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x20));
      if (cVar1 == '\0') {
        return;
      }
      slot = *(uint **)(entry + 0x20);
      pch_relocate_slot_once(&g_pch_image,slot + 2);
      cVar1 = pch_relocate_slot_once(&g_pch_image,slot + 1);
      if (cVar1 == '\0') {
        return;
      }
      entry = slot[1];
      if ((*(uint *)(entry + -8) & 0x1f) == 4) {
        pch_relocate_class_member_list(slot[1]);
        return;
      }
      bVar2 = (byte)*(uint *)(entry + -8) & 0x1f;
      if ((bVar2 != 0x10) && (bVar2 != 0x11)) goto LAB_1048bce8;
    }
    bVar2 = (byte)*(uint *)(entry + -8) & 0x1f;
  } while ((bVar2 == 0x10) || (bVar2 == 0x11));
LAB_1048bce8:
  pch_relocate_symbol_list(slot[1]);
  return;
}

