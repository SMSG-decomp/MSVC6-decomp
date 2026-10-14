char * __cdecl decorate_string_literal_name_body(char *out,ushort *text,uint length,char wide)

{
  ushort uVar1;
  char *out_00;
  uint uVar2;
  byte *pbVar3;
  
  builtin_strncpy(out,"??_C@_",6);
  if (wide == '\0') {
    out[6] = '0';
  }
  else {
    out[6] = '1';
  }
  out_00 = decorate_number(out + 7,length);
  uVar2 = crc16_update((c1_u8 *)text,length,0);
  pbVar3 = (byte *)decorate_number(out_00,uVar2);
  if (wide == '\0') {
    if (0x20 < length) {
      length = 0x20;
    }
    for (; length != 0; length = length - 1) {
      uVar1 = *text;
      text = (ushort *)((int)text + 1);
      pbVar3 = decorate_string_literal_char(pbVar3,(byte)uVar1);
    }
  }
  else {
    uVar2 = length >> 1;
    if (0x14 < uVar2) {
      uVar2 = 0x14;
    }
    if (uVar2 != 0) {
      do {
        uVar1 = *text;
        text = text + 1;
        pbVar3 = decorate_string_literal_char(pbVar3,(byte)(uVar1 >> 8));
        pbVar3 = decorate_string_literal_char(pbVar3,(byte)uVar1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      *pbVar3 = 0x40;
      return (char *)(pbVar3 + 1);
    }
  }
  *pbVar3 = 0x40;
  return (char *)(pbVar3 + 1);
}

