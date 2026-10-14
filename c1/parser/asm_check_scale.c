int __cdecl asm_check_scale(uint scale)

{
  int iVar1;
  
  iVar1 = 0;
  if ((8 < scale) || ((scale & scale - 1) != 0)) {
    diag_error(0x1a7,scale);
  }
  while (scale = scale >> 1, scale != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

