void __cdecl pch_relocate_symbol_chain(byte *sym)

{
  byte bVar1;
  char cVar2;
  uint *entry;
  uint *puVar3;
  
  if (sym == (byte *)0x0) {
    return;
  }
  bVar1 = *sym & 0x1f;
  if (bVar1 == 4) {
    puVar3 = (uint *)(sym + 8);
    pch_relocate_slot_once(&g_pch_image,puVar3);
    pch_relocate_symbol(sym);
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0xc));
    if (cVar2 != '\0') {
      entry = *(uint **)(sym + 0xc);
      if ((entry[-2] & 0x1f) == 4) {
        pch_relocate_class_member_list((int)entry);
      }
      else {
        bVar1 = (byte)entry[-2] & 0x1f;
        if ((bVar1 != 0x10) && (bVar1 != 0x11)) goto LAB_1048acab;
        pch_relocate_symbol_list_c((int)entry);
      }
    }
LAB_1048abbe:
    cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3 + 8);
    if (cVar2 != '\0') {
      pch_relocate_class_scope_list(puVar3[8]);
      return;
    }
  }
  else {
    if ((bVar1 == 0x10) || (bVar1 == 0x11)) {
      puVar3 = (uint *)(sym + 8);
      pch_relocate_slot_once(&g_pch_image,puVar3);
      pch_relocate_symbol(sym);
      cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0xc));
      if (cVar2 != '\0') {
        entry = *(uint **)(sym + 0xc);
        if ((entry[-2] & 0x1f) == 4) {
          pch_relocate_class_member_list((int)entry);
        }
        else {
          bVar1 = (byte)entry[-2] & 0x1f;
          if ((bVar1 != 0x10) && (bVar1 != 0x11)) goto LAB_1048acc4;
          pch_relocate_symbol_list_c((int)entry);
        }
      }
    }
    else {
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 8));
      pch_relocate_symbol(sym);
      cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0xc));
      if (cVar2 == '\0') {
        return;
      }
      entry = *(uint **)(sym + 0xc);
      puVar3 = entry;
      if ((entry[-2] & 0x1f) == 4) {
LAB_1048acab:
        pch_relocate_symbol_list((int)entry);
        goto LAB_1048abbe;
      }
      bVar1 = (byte)entry[-2] & 0x1f;
      if ((bVar1 != 0x10) && (bVar1 != 0x11)) {
        pch_relocate_symbol_list((int)entry);
        return;
      }
LAB_1048acc4:
      pch_relocate_symbol_list((int)entry);
    }
    cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3 + 3);
    if (cVar2 != '\0') {
      pch_relocate_symbol_list(puVar3[3]);
      return;
    }
  }
  return;
}

