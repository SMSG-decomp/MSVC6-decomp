ulonglong __fastcall _aullshr(byte count,uint hi,uint lo)

{
  if (0x3f < count) {
    return 0;
  }
  if (0x1f < count) {
    return (ulonglong)(hi >> (count & 0x1f));
  }
  return CONCAT44(hi >> (count & 0x1f),lo >> (count & 0x1f) | hi << 0x20 - (count & 0x1f));
}

