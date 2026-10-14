longlong __cdecl allshr(uint32_t lo,int32_t hi,uint8_t count)

{
  int iVar1;
  
  iVar1 = hi >> 0x1f;
  if (0x3f < count) {
    return CONCAT44(iVar1,iVar1);
  }
  if (0x1f < count) {
    return CONCAT44(iVar1,hi >> (count & 0x1f));
  }
  return CONCAT44(hi >> (count & 0x1f),lo >> (count & 0x1f) | hi << 0x20 - (count & 0x1f));
}

