int64_t shift_loop_noop(uint32_t lo,uint32_t hi)

{
  int iVar1;
  uint64_t uVar2;
  
  iVar1 = 0;
  for (uVar2 = aullshr('\x01',hi,lo); uVar2 != 0;
      uVar2 = aullshr('\x01',(uint32_t)(uVar2 >> 0x20),(uint32_t)uVar2)) {
    iVar1 = iVar1 + 1;
  }
  return (int64_t)iVar1;
}

