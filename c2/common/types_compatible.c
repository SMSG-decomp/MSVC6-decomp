int __fastcall types_compatible(uint16_t a,uint16_t b)

{
  byte bVar1;
  
  if (a == b) {
    return 1;
  }
  bVar1 = (byte)(b >> 8);
  if ((1 << (byte)(a >> 0xc) & 0xeU) == 0) {
    if (((a & 0xf000) == 0x5000) &&
       ((((1 << (bVar1 >> 4) & 0xeU) != 0 || ((b & 0xf000) == 0x5000)) && (((a ^ b) & 0xfff) == 0)))
       ) {
      return 1;
    }
  }
  else if ((((1 << (bVar1 >> 4) & 0xeU) != 0) || ((b & 0xf000) == 0x5000)) &&
          (((a ^ b) & 0xfff) == 0)) {
    return 1;
  }
  return 0;
}

