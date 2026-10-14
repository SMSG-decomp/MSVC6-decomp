longlong __fastcall _allshl(byte count,uint lo,uint hi)

{
  if (0x3f < count) {
    return 0;
  }
  if (count < 0x20) {
    return CONCAT44(hi << (count & 0x1f) | lo >> 0x20 - (count & 0x1f),lo << (count & 0x1f));
  }
  return (ulonglong)(lo << (count & 0x1f)) << 0x20;
}

