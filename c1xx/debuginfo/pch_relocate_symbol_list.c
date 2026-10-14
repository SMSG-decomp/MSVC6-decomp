void __fastcall pch_relocate_symbol_list(int entry)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)entry);
    pch_relocate_symbol((byte *)(entry + -8));
    cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 4));
    if (cVar3 == '\0') {
      return;
    }
    entry = *(uint *)(entry + 4);
    if ((*(uint *)(entry + -8) & 0x1f) == 4) {
      pch_relocate_symbol_list(entry);
      cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x20));
      if (cVar3 == '\0') {
        return;
      }
      uVar2 = *(uint *)(entry + 0x20);
      pch_relocate_slot_once(&g_pch_image,(uint *)(uVar2 + 8));
      cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(uVar2 + 4));
      if (cVar3 == '\0') {
        return;
      }
      entry = *(uint *)(uVar2 + 4);
      if ((*(uint *)(entry + -8) & 0x1f) == 4) {
        pch_relocate_class_member_list(*(int *)(uVar2 + 4));
        return;
      }
      bVar1 = (byte)*(uint *)(entry + -8);
    }
    else {
      bVar1 = (byte)*(uint *)(entry + -8);
    }
    if (((bVar1 & 0x1f) == 0x10) || ((bVar1 & 0x1f) == 0x11)) {
      pch_relocate_symbol_list(entry);
      cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0xc));
      if (cVar3 == '\0') {
        return;
      }
      entry = *(uint *)(entry + 0xc);
    }
  } while( true );
}

