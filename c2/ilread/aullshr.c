uint64_t __fastcall aullshr(uint8_t count,uint32_t hi,uint32_t lo)

{
  if (0x3f < count) {
    return 0;
  }
  if (0x1f < count) {
    return (uint64_t)(hi >> (count & 0x1f));
  }
  return CONCAT44(hi >> (count & 0x1f),lo >> (count & 0x1f) | hi << 0x20 - (count & 0x1f));
}

