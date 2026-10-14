uint __cdecl sym_kind_in_lookup_mask(c1_u8 *entry,uint flags)

{
  byte bVar1;
  
  bVar1 = entry[-8] & 0x1f;
  if (bVar1 == 4) {
    return flags >> 5 & 1;
  }
  if (bVar1 == 0xf) {
    return flags & 1;
  }
  if (bVar1 == 0x19) {
    return flags >> 8 & 1;
  }
  if (((((bVar1 != 3) && (bVar1 != 2)) && ((entry[-8] & 0x1f) != 0x11)) &&
      (((entry[-8] & 0x1f) != 8 && (bVar1 != 5)))) && (bVar1 != 0x1a)) {
    if (((entry[-8] & 0x1f) == 10) && ((entry[0x18] & 7) == 7)) {
      return CONCAT31((int3)(flags >> 8),(byte)flags >> 1) & 0xffffff01;
    }
    return flags >> 4 & 1;
  }
  return flags >> 1 & 1;
}

