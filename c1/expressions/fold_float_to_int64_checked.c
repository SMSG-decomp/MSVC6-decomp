int __cdecl fold_float_to_int64_checked(float10 *value,longlong *out)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  uint uVar8;
  bool bVar9;
  longlong lVar10;
  double dVar11;
  double dvalue;
  byte *local_144;
  double truncated;
  byte local_138 [312];
  
  fold_float_to_double_checked(value,&dvalue);
  pbVar6 = local_138;
  for (iVar5 = 0x4d; iVar5 != 0; iVar5 = iVar5 + -1) {
    pbVar6[0] = 0;
    pbVar6[1] = 0;
    pbVar6[2] = 0;
    pbVar6[3] = 0;
    pbVar6 = pbVar6 + 4;
  }
  *pbVar6 = 0;
  local_144 = local_138;
  if ((double)CONCAT44(dvalue._4_4_,dvalue._0_4_) < 0.0) {
    dVar11 = ceil((double)CONCAT44(dvalue._4_4_,dvalue._0_4_));
  }
  else {
    dVar11 = floor((double)CONCAT44(dvalue._4_4_,dvalue._0_4_));
  }
  truncated._4_4_ = (undefined4)((ulonglong)dVar11 >> 0x20);
  uVar3 = truncated._4_4_;
  truncated._0_4_ = SUB84(dVar11,0);
  uVar4 = truncated._0_4_;
  truncated = dVar11;
  sprintf((char *)local_138,"%.lf",uVar4,uVar3);
  lVar10 = 0;
  *(undefined4 *)out = 0;
  *(undefined4 *)((int)out + 4) = 0;
  pbVar6 = local_138;
  bVar9 = false;
  if (local_138[0] == 0x2d) {
    bVar9 = true;
  }
  else if (local_138[0] != 0x2b) goto LAB_1063056a;
  pbVar6 = local_138 + 1;
LAB_1063056a:
  iVar5 = isdigit((uint)*pbVar6);
  while (iVar5 != 0) {
    bVar1 = pbVar6[1];
    lVar10 = lVar10 + ((char)*pbVar6 + -0x30);
    uVar8 = (uint)lVar10;
    iVar5 = (int)((ulonglong)lVar10 >> 0x20);
    pbVar6 = pbVar6 + 1;
    if (bVar1 == 0) {
      if (bVar9) {
        lVar10 = CONCAT44(-(iVar5 + (uint)(uVar8 != 0)),-uVar8);
      }
      break;
    }
    lVar10 = _allmul(uVar8,iVar5,10,0);
    iVar5 = isdigit((uint)bVar1);
  }
  *out = lVar10;
  if (local_138[0] == 0x2d) {
    local_144 = local_138 + 1;
  }
  uVar8 = 0xffffffff;
  pbVar6 = local_144;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != 0);
  if (~uVar8 - 1 < 0x14) {
    return 0;
  }
  uVar8 = 0xffffffff;
  pbVar6 = local_144;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != 0);
  if (0x14 < ~uVar8 - 1) {
    return 1;
  }
  pcVar7 = "18446744073709551615";
  while( true ) {
    bVar1 = *local_144;
    bVar9 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = local_144[1];
    bVar9 = bVar1 < (byte)pcVar7[1];
    if (bVar1 != pcVar7[1]) break;
    local_144 = local_144 + 2;
    pcVar7 = pcVar7 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar8 = (uint)(bVar9 != 0);
  uVar2 = 1 - bVar9;
  return (uint)(uVar2 != uVar8 && -1 < (int)(uVar2 - uVar8));
}

