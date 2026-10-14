byte * __cdecl decorate_string_literal_char(byte *out,byte c)

{
  int iVar1;
  byte *pbVar2;
  
  if (((((c & 0x80) != 0) || (iVar1 = isalnum((uint)c), iVar1 == 0)) && (c != 0x5f)) && (c != 0x24))
  {
    *out = 0x3f;
    pbVar2 = out + 1;
    iVar1 = isalpha((int)(char)c & 0x7f);
    if (iVar1 == 0) {
      switch((int)(char)c) {
      case 9:
        *pbVar2 = 0x37;
        return out + 2;
      case 10:
        *pbVar2 = 0x36;
        return out + 2;
      default:
        *pbVar2 = 0x24;
        out[2] = ((char)c >> 4 & 0xfU) + 0x41;
        out[3] = (c & 0xf) + 0x41;
        return out + 4;
      case 0x20:
        *pbVar2 = 0x35;
        return out + 2;
      case 0x27:
        *pbVar2 = 0x38;
        return out + 2;
      case 0x2c:
        *pbVar2 = 0x30;
        return out + 2;
      case 0x2d:
        *pbVar2 = 0x39;
        return out + 2;
      case 0x2e:
        *pbVar2 = 0x34;
        return out + 2;
      case 0x2f:
        *pbVar2 = 0x31;
        return out + 2;
      case 0x3a:
        *pbVar2 = 0x33;
        return out + 2;
      case 0x5c:
        *pbVar2 = 0x32;
        return out + 2;
      }
    }
    *pbVar2 = c & 0x7f;
    return out + 2;
  }
  *out = c;
  return out + 1;
}

