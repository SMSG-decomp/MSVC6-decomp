int64_t __fastcall sign_extend_to_size(c2_operand *k,uint32_t v)

{
  ushort uVar1;
  uint uVar2;
  int hi;
  int iVar3;
  int64_t iVar4;
  
  uVar1 = k->type;
  hi = (int)v >> 0x1f;
  if ((uVar1 & 0xfff) == 4) {
    return (int64_t)(int)v;
  }
  if ((uVar1 & 0xfff) < 5) {
    v = (int)v >> (('\x04' - (char)uVar1) * '\b' & 0x1fU);
    hi = (int)v >> 0x1f;
  }
  else {
    iVar3 = (uVar1 & 0xfff) - 4;
    if (iVar3 != 0) {
      uVar2 = v & 0xff;
      do {
        iVar4 = allshl('\b',hi,v);
        hi = (int)((ulonglong)iVar4 >> 0x20);
        v = (uint)iVar4 | uVar2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      return CONCAT44(hi,v);
    }
  }
  return CONCAT44(hi,v);
}

