uint64_t const_normalize(uint16_t type,uint32_t lo,int32_t hi)

{
  uint8_t count;
  int64_t iVar1;
  uint64_t uVar2;
  
  count = ('\b' - (char)type) * '\b';
  if ((type & 0xf000) != 0x2000) {
    iVar1 = allshl(count,hi,lo);
    uVar2 = allshr((uint32_t)iVar1,(int32_t)((ulonglong)iVar1 >> 0x20),count);
    return uVar2;
  }
  uVar2 = aullshr(count,0xffffffff,0xffffffff);
  return CONCAT44(hi & (uint)(uVar2 >> 0x20),lo & (uint)uVar2);
}

