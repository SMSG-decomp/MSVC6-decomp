void __cdecl pch_relocate_symbol(byte *sym)

{
  char cVar1;
  uint slot;
  
  if (sym != (byte *)0x0) {
    switch(*sym & 0x1f) {
    case 4:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      pch_relocate_symbol_symtab((c1_symbol *)sym);
      return;
    case 7:
    case 8:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x28));
      return;
    case 10:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x2c));
      if ((cVar1 != '\0') && (slot = *(uint *)(sym + 0x2c), slot != 0)) {
        do {
          pch_relocate_slot_once(&g_pch_image,slot);
          pch_relocate_slot_once(&g_pch_image,slot + 4);
          slot = *(uint *)(slot + 4);
        } while (slot != 0);
        return;
      }
      break;
    case 0xb:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x24));
      return;
    case 0xe:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x24));
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x2c));
      break;
    case 0x17:
      if (*(int *)(sym + 0x24) != 0) {
        pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x24));
        pch_relocate_tree(*(c1_node **)(sym + 0x24));
      }
    case 2:
    case 3:
    case 5:
    case 6:
    case 9:
    case 0xc:
    case 0xd:
    case 0x16:
      pch_relocate_slot_once(&g_pch_image,(uint)(sym + 0x14));
      return;
    }
  }
  return;
}

