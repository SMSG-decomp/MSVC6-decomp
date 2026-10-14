void __cdecl pch_relocate_symbol(byte *sym)

{
  char cVar1;
  uint *puVar2;
  
  if (sym != (byte *)0x0) {
    switch(*sym & 0x1f) {
    case 4:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_class_slot_24((int)sym);
      pch_relocate_class_layout((int)sym);
      return;
    case 7:
    case 8:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x30));
      return;
    case 10:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      if ((sym[0x21] & 0x20) != 0) {
        pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x2c));
      }
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x34));
      if ((cVar1 != '\0') && (puVar2 = *(uint **)(sym + 0x34), puVar2 != (uint *)0x0)) {
        do {
          pch_relocate_slot_once(&g_pch_image,puVar2);
          pch_relocate_slot_once(&g_pch_image,puVar2 + 1);
          puVar2 = (uint *)puVar2[1];
        } while (puVar2 != (uint *)0x0);
        return;
      }
      break;
    case 0xb:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x24));
      return;
    case 0xe:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x24));
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x2c));
      return;
    case 0x14:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x24));
      return;
    case 0x17:
      if (*(int *)(sym + 0x2c) != 0) {
        pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x2c));
        pch_relocate_tree(*(c1_node **)(sym + 0x2c));
      }
    case 2:
    case 3:
    case 5:
    case 6:
    case 9:
    case 0xc:
    case 0xd:
    case 0x12:
    case 0x16:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      return;
    case 0x19:
      puVar2 = (uint *)(sym + 0x14);
      pch_relocate_slot_once(&g_pch_image,puVar2);
      pch_relocate_slot_once(&g_pch_image,(uint *)*puVar2);
      (**(code **)(**(int **)*puVar2 + 0x20))();
      return;
    case 0x1a:
      pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x14));
      pch_relocate_slot_once(&g_pch_image,*(uint **)(sym + 0x14));
    }
  }
  return;
}

