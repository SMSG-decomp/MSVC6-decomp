uint16_t __fastcall usual_arithmetic_type(uint16_t a,uint16_t b)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = a & 0xf000;
  if (uVar2 == 0x3000) {
    if ((b & 0xf000) != 0x3000) {
      return a;
    }
    if ((b & 0xfff) < (a & 0xfff)) {
      return a & 0xfff | 0x1000;
    }
    return b & 0xfff | 0x1000;
  }
  uVar1 = b & 0xf000;
  if (uVar1 != 0x3000) {
    if (a == b) {
      return a;
    }
    if (uVar2 == 0x4000) {
      if (uVar1 != 0x4000) {
        return a;
      }
      if ((a & 0xfff) < (b & 0xfff)) {
        return b;
      }
      return a;
    }
    if (uVar1 != 0x4000) {
      if ((b & 0xfff) < (a & 0xfff)) {
        return a;
      }
      if (((b & 0xfff) <= (a & 0xfff)) && (uVar2 == 0x2000)) {
        return a;
      }
    }
  }
  return b;
}

