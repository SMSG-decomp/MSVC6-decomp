int __fastcall log2_floor(uint32_t x)

{
  int iVar1;
  
  iVar1 = 0;
  while (x = x >> 1, x != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

