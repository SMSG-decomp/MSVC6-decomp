c2_div_magic * __fastcall signed_div_magic(int divisor)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_8;
  
  if ((2 < divisor) && ((uint)divisor < 0xd)) {
    return (c2_div_magic *)(g_mul_decomp_op_cost + divisor * 2 + 8);
  }
  uVar4 = divisor >> 0x1f;
  uVar7 = (divisor ^ uVar4) - uVar4;
  local_8 = 0x1f;
  uVar6 = ((0x80000000 - uVar4) - (0x80000000 - uVar4) % uVar7) - 1;
  uVar2 = (uint)(0x80000000 / (ulonglong)uVar6);
  uVar4 = 0x80000000 - uVar2 * uVar6;
  iVar3 = (int)(0x80000000 / (ulonglong)uVar7);
  uVar5 = 0x80000000 - iVar3 * uVar7;
  iVar1 = local_8;
  do {
    local_8 = iVar1;
    uVar4 = uVar4 * 2;
    uVar2 = uVar2 * 2;
    if (uVar6 <= uVar4) {
      uVar2 = uVar2 + 1;
      uVar4 = uVar4 - uVar6;
    }
    uVar5 = uVar5 * 2;
    iVar3 = iVar3 * 2;
    if (uVar7 <= uVar5) {
      iVar3 = iVar3 + 1;
      uVar5 = uVar5 - uVar7;
    }
    iVar1 = local_8 + 1;
  } while ((uVar2 < uVar7 - uVar5) || ((uVar2 == uVar7 - uVar5 && (uVar4 == 0))));
  g_sdiv_magic_result.multiplier = iVar3 + 1;
  if (divisor < 0) {
    g_sdiv_magic_result.multiplier = -g_sdiv_magic_result.multiplier;
  }
  g_sdiv_magic_result.shift = local_8 + -0x1f;
  return &g_sdiv_magic_result;
}

