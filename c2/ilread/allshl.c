int64_t __fastcall allshl(uint8_t count,int32_t hi,uint32_t lo)

{
  if (0x3f < count) {
    return 0;
  }
  if (0x1f < count) {
    return (ulonglong)(lo << (count & 0x1f)) << 0x20;
  }
  return CONCAT44(hi << (count & 0x1f) | lo >> 0x20 - (count & 0x1f),lo << (count & 0x1f));
}

