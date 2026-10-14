byte * __cdecl str_find_trailing_space(byte *s,byte *end)

{
  int iVar1;
  byte *pbVar2;
  
  if (end == (byte *)0x0) {
    end = (byte *)strchr((char *)s,0);
  }
  pbVar2 = (byte *)0x0;
  if (s < end) {
    do {
      iVar1 = isspace((uint)*s);
      if (iVar1 == 0) {
        pbVar2 = (byte *)0x0;
      }
      else if (pbVar2 == (byte *)0x0) {
        pbVar2 = s;
      }
      s = s + (((byte)_mbctype_exref[*s + 1] & 4) != 0) + 1;
    } while (s < end);
    if (pbVar2 != (byte *)0x0) {
      return pbVar2;
    }
  }
  return end;
}

