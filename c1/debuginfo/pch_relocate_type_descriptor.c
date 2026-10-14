void __cdecl pch_relocate_type_descriptor(c1_type *type)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  
  pch_relocate_slot_once(&g_pch_image,(uint)&type->base);
  if ((type->code & 0x300) != 0) {
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&type->extra);
    if (cVar1 != '\0') {
      pch_relocate_symbol_chain((type->extra).sym);
    }
  }
  bVar2 = (byte)type->code;
  if ((char)bVar2 < '\0') {
    uVar3 = type->code & 0x8f;
    if ((uVar3 == 0x80) || (uVar3 == 0x82)) {
      if ((type->flags & 0x18) == 0x18) {
        pch_relocate_slot_once(&g_pch_image,(uint)&type->extra);
      }
    }
    else if ((bVar2 & 0x83) == 0x81) {
      pch_relocate_slot_once(&g_pch_image,(uint)&type->extra);
      return;
    }
  }
  return;
}

