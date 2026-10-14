int __fastcall cv_put_numeric_leaf(uint8_t *out,int32_t value)

{
  uint8_t uVar1;
  uint8_t uVar2;
  
  uVar2 = (uint8_t)((uint)value >> 8);
  uVar1 = (uint8_t)value;
  if (value < 0) {
    if ((value < 0x80) && (-0x81 < value)) {
      *out = '\0';
      out[1] = 0x80;
      out[2] = uVar1;
      return 3;
    }
    if ((value < 0x8000) && (-0x8001 < value)) {
      *out = '\x01';
      out[1] = 0x80;
      out[2] = uVar1;
      out[3] = uVar2;
      return 4;
    }
    *out = '\x03';
  }
  else {
    if (value < 0x8000) {
      *out = uVar1;
      out[1] = uVar2;
      return 2;
    }
    if (value < 0x10000) {
      *out = '\x02';
      out[1] = 0x80;
      out[2] = uVar1;
      out[3] = uVar2;
      return 4;
    }
    *out = '\x04';
  }
  out[1] = 0x80;
  out[2] = uVar1;
  out[3] = uVar2;
  out[4] = (uint8_t)((uint)value >> 0x10);
  out[5] = (uint8_t)((uint)value >> 0x18);
  return 6;
}

