void __cdecl pch_relocate_type_descriptor(ushort *type)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)(type + 2));
  if ((*type & 0x300) != 0) {
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)(type + 4));
    if (cVar2 != '\0') {
      pch_relocate_symbol_chain(*(byte **)(type + 4));
    }
  }
  uVar1 = *type;
  if ((char)(byte)uVar1 < '\0') {
    uVar3 = uVar1 & 0x8f;
    if ((uVar3 == 0x80) || (uVar3 == 0x82)) {
      if ((type[1] & 0x18) != 0x18) {
        return;
      }
    }
    else if (((byte)uVar1 & 0x83) != 0x81) {
      if ((uVar3 == 0x83) && (uVar1 == 0x4083)) {
        pch_relocate_slot_once(&g_pch_image,(uint *)(type + 4));
        pch_relocate_tree(*(c1_node **)(type + 4));
        return;
      }
      if (uVar3 != 0x8a) {
        if (uVar3 != 0x8e) {
          return;
        }
        pch_relocate_slot_once(&g_pch_image,(uint *)(type + 4));
        return;
      }
    }
    pch_relocate_slot_once(&g_pch_image,(uint *)(type + 4));
  }
  return;
}

