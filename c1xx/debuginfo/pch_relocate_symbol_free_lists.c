void __cdecl pch_relocate_symbol_free_lists(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  uint **ppuVar5;
  
  ppuVar5 = g_symbol_free_lists + 1;
  do {
    puVar4 = *ppuVar5;
    if (puVar4 != (uint *)0x0) {
      pch_relocate_slot_once(&g_pch_image,puVar4);
      pch_relocate_symbol((byte *)(puVar4 + -2));
      cVar2 = pch_relocate_slot_once(&g_pch_image,puVar4 + 1);
      if (cVar2 != '\0') {
        uVar3 = puVar4[1];
        if ((*(byte *)(uVar3 - 8) & 0x1f) == 4) {
          pch_relocate_symbol_list(uVar3);
          cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 0x20));
          if (cVar2 != '\0') {
            uVar3 = *(uint *)(uVar3 + 0x20);
            pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 8));
            puVar4 = (uint *)(uVar3 + 4);
            cVar2 = pch_relocate_slot_once(&g_pch_image,puVar4);
            if (cVar2 != '\0') {
              uVar3 = *puVar4;
              if ((*(byte *)(uVar3 - 8) & 0x1f) != 4) {
                bVar1 = *(byte *)(uVar3 - 8);
                goto joined_r0x1048a68f;
              }
              pch_relocate_class_member_list(uVar3);
            }
          }
        }
        else {
          bVar1 = *(byte *)(uVar3 - 8);
joined_r0x1048a68f:
          if (((bVar1 & 0x1f) == 0x10) || ((bVar1 & 0x1f) == 0x11)) {
            pch_relocate_symbol_list(uVar3);
            cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(uVar3 + 0xc));
            if (cVar2 == '\0') goto LAB_1048a665;
            uVar3 = *(uint *)(uVar3 + 0xc);
          }
          pch_relocate_symbol_list(uVar3);
        }
      }
    }
LAB_1048a665:
    ppuVar5 = ppuVar5 + 1;
    if (0x104d15a7 < (int)ppuVar5) {
      return;
    }
  } while( true );
}

