int __cdecl mul_overflows(uint32_t a,uint32_t b,int is_unsigned,int size)

{
  if (size == 2) {
    if (is_unsigned == 0) {
      if ((int)(short)((int)(short)a * (int)(short)b) == (int)(short)a * (int)(short)b) {
        return 0;
      }
    }
    else if ((short)((a & 0xffff) * (b & 0xffff) >> 0x10) == 0) {
      return 0;
    }
  }
  else if (size < 2) {
    if (is_unsigned == 0) {
      if ((short)(char)((short)(char)(byte)a * (short)(char)(byte)b) ==
          (short)((short)(char)(byte)a * (short)(char)(byte)b)) {
        return 0;
      }
    }
    else if ((char)((ushort)((ushort)(byte)a * (ushort)(byte)b) >> 8) == '\0') {
      return 0;
    }
  }
  else if (is_unsigned == 0) {
    if ((longlong)(int)((longlong)(int)a * (longlong)(int)b) == (longlong)(int)a * (longlong)(int)b)
    {
      return 0;
    }
  }
  else if ((int)((ulonglong)a * (ulonglong)b >> 0x20) == 0) {
    return 0;
  }
  return 1;
}

