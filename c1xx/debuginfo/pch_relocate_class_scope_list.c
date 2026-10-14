void __fastcall pch_relocate_class_scope_list(int cell)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)(cell + 8));
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(cell + 4U));
    if (cVar1 == '\0') {
      return;
    }
    puVar4 = *(uint **)(cell + 4U);
    if ((puVar4[-2] & 0x1f) == 4) {
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
      puVar4 = puVar4 + 8;
    }
    else {
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
        uVar3 = puVar4[1];
        if ((*(byte *)(uVar3 - 8) & 0x1f) != 4) {
          uVar3 = puVar4[1];
          bVar2 = *(byte *)(uVar3 - 8) & 0x1f;
          if ((bVar2 == 0x10) || (bVar2 == 0x11)) {
            pch_relocate_symbol_list_c(uVar3);
            return;
          }
          goto LAB_1048befc;
        }
        pch_relocate_symbol_list(uVar3);
        puVar4 = (uint *)(uVar3 + 0x20);
      }
      else {
        pch_relocate_slot_once(&g_pch_image,puVar4);
        pch_relocate_symbol((byte *)(puVar4 + -2));
        cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4 + 1);
        if (cVar1 == '\0') {
          return;
        }
        uVar3 = puVar4[1];
        if ((*(byte *)(uVar3 - 8) & 0x1f) != 4) {
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
LAB_1048befc:
          pch_relocate_symbol_list(uVar3);
          return;
        }
        pch_relocate_symbol_list(uVar3);
        puVar4 = (uint *)(uVar3 + 0x20);
      }
    }
    cVar1 = pch_relocate_slot_once(&g_pch_image,puVar4);
    if (cVar1 == '\0') {
      return;
    }
    cell = *puVar4;
  } while( true );
}

