int __fastcall conversion_changes_value(uint16_t from,uint16_t to)

{
  byte bVar1;
  
  if (from != to) {
    if ((from & 0xfff) < (to & 0xfff)) {
      return 1;
    }
    bVar1 = (byte)(from >> 8);
    if ((((from ^ to) & 0xfff) == 0) &&
       (((1 << (bVar1 >> 4) & 0xeU) != 0) != ((1 << (byte)(to >> 0xc) & 0xeU) != 0))) {
      return 1;
    }
    if (((1 << (bVar1 >> 4) & 0xeU) != 0) && ((to & 0xf000) == 0x4000)) {
      return 1;
    }
  }
  return 0;
}

