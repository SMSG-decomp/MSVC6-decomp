char * __cdecl decorate_string_literal_name_body(char *out,byte *bytes,uint length,char wide)

{
  byte c;
  char *out_00;
  uint uVar1;
  byte *pbVar2;
  undefined2 wide_char;
  
  builtin_strncpy(out,"??_C@_",6);
  if (wide == '\0') {
    out[6] = '0';
  }
  else {
    out[6] = '1';
  }
  out_00 = decorate_number(out + 7,length);
  uVar1 = crc16_update(bytes,length,0);
  pbVar2 = (byte *)decorate_number(out_00,uVar1);
  if (wide == '\0') {
    if (0x20 < length) {
      length = 0x20;
    }
    for (; length != 0; length = length - 1) {
      c = *bytes;
      bytes = bytes + 1;
      pbVar2 = decorate_string_literal_char(pbVar2,c);
    }
  }
  else {
    uVar1 = length >> 1;
    if (0x14 < uVar1) {
      uVar1 = 0x14;
    }
    if (uVar1 != 0) {
      do {
        wide_char = *(undefined2 *)bytes;
        bytes = bytes + 2;
        pbVar2 = decorate_string_literal_char(pbVar2,(byte)((ushort)wide_char >> 8));
        pbVar2 = decorate_string_literal_char(pbVar2,(byte)wide_char);
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
      *pbVar2 = 0x40;
      return (char *)(pbVar2 + 1);
    }
  }
  *pbVar2 = 0x40;
  return (char *)(pbVar2 + 1);
}

