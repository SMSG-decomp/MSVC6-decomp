byte * __cdecl str_find_trailing_space(byte *text,byte *end)

{
  int iVar1;
  byte *pbVar2;
  
  if (end == (byte *)0x0) {
    end = (byte *)strchr((char *)text,0);
  }
  pbVar2 = (byte *)0x0;
  if (text < end) {
    do {
      iVar1 = isspace((uint)*text);
      if (iVar1 == 0) {
        pbVar2 = (byte *)0x0;
      }
      else if (pbVar2 == (byte *)0x0) {
        pbVar2 = text;
      }
      text = text + (((byte)_mbctype_exref[*text + 1] & 4) != 0) + 1;
    } while (text < end);
    if (pbVar2 != (byte *)0x0) {
      return pbVar2;
    }
  }
  return end;
}

