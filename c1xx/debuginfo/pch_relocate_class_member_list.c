void __fastcall pch_relocate_class_member_list(int entry)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  
LAB_1048b976:
  do {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint *)entry);
      pch_relocate_symbol((byte *)(entry + -8));
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 4));
      if (cVar1 != '\0') {
        uVar3 = *(uint *)(entry + 4);
        if ((*(byte *)(uVar3 - 8) & 0x1f) == 4) {
          pch_relocate_class_member_list(uVar3);
        }
        else {
          bVar2 = *(byte *)(uVar3 - 8) & 0x1f;
          if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
            pch_relocate_symbol_list(uVar3);
            cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 0xc));
            if (cVar1 == '\0') goto LAB_1048b9b7;
            uVar3 = *(uint *)(uVar3 + 0xc);
          }
          pch_relocate_symbol_list(uVar3);
        }
      }
LAB_1048b9b7:
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x20));
      if (cVar1 == '\0') {
        return;
      }
      uVar3 = *(uint *)(entry + 0x20);
      pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 8));
      puVar4 = (uint *)(uVar3 + 4);
      cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4);
      if (cVar1 == '\0') {
        return;
      }
      puVar4 = (uint *)*puVar4;
      entry = (int)puVar4;
    } while ((puVar4[-2] & 0x1f) == 4);
    bVar2 = (byte)puVar4[-2] & 0x1f;
    if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
      pch_relocate_slot_once(&g_pch_image,puVar4);
      pch_relocate_symbol((byte *)(puVar4 + -2));
      cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4 + 1);
      if (cVar1 != '\0') {
        uVar3 = puVar4[1];
        if ((*(byte *)(uVar3 - 8) & 0x1f) == 4) {
          pch_relocate_class_member_list(uVar3);
        }
        else {
          bVar2 = *(byte *)(uVar3 - 8) & 0x1f;
          if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
            pch_relocate_symbol_list_c(uVar3);
          }
          else {
            pch_relocate_symbol_list(uVar3);
          }
        }
      }
      cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4 + 3);
      if (cVar1 == '\0') {
        return;
      }
      puVar4 = (uint *)puVar4[3];
      pch_relocate_slot_once(&g_pch_image,puVar4);
      pch_relocate_symbol((byte *)(puVar4 + -2));
      cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4 + 1);
      if (cVar1 == '\0') {
        return;
      }
      entry = puVar4[1];
      if ((*(uint *)(entry + -8) & 0x1f) != 4) {
        uVar3 = puVar4[1];
        bVar2 = *(byte *)(uVar3 - 8) & 0x1f;
        if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
          pch_relocate_symbol_list_c(uVar3);
          return;
        }
        goto LAB_1048bb94;
      }
      goto LAB_1048b976;
    }
    pch_relocate_slot_once(&g_pch_image,puVar4);
    pch_relocate_symbol((byte *)(puVar4 + -2));
    cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4 + 1);
    if (cVar1 == '\0') {
      return;
    }
    entry = puVar4[1];
    if ((*(uint *)(entry + -8) & 0x1f) != 4) {
      uVar3 = puVar4[1];
      bVar2 = *(byte *)(uVar3 - 8) & 0x1f;
      if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
        pch_relocate_symbol_list(uVar3);
        cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 0xc));
        if (cVar1 == '\0') {
          return;
        }
        pch_relocate_symbol_list(*(uint *)(uVar3 + 0xc));
        return;
      }
LAB_1048bb94:
      pch_relocate_symbol_list(uVar3);
      return;
    }
  } while( true );
}

