int __cdecl fold_float_to_int64_checked(void *value,c1_u32 *out)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  uint uVar6;
  bool bVar7;
  longlong lVar8;
  double double_value;
  byte *local_144;
  double rounded;
  byte local_138 [312];
  
  fold_float_to_double_checked(value,&double_value);
  pbVar4 = local_138;
  for (iVar3 = 0x4d; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  *pbVar4 = 0;
  local_144 = local_138;
  if ((double)CONCAT44(double_value._4_4_,double_value._0_4_) < 0.0) {
    rounded = ceil((double)CONCAT44(double_value._4_4_,double_value._0_4_));
  }
  else {
    rounded = floor((double)CONCAT44(double_value._4_4_,double_value._0_4_));
  }
  sprintf((char *)local_138,"%.lf",rounded);
  lVar8 = 0;
  *out = 0;
  out[1] = 0;
  pbVar4 = local_138;
  bVar7 = false;
  if (local_138[0] == 0x2d) {
    bVar7 = true;
  }
  else if (local_138[0] != 0x2b) goto LAB_1046515f;
  pbVar4 = local_138 + 1;
LAB_1046515f:
  iVar3 = isdigit((uint)*pbVar4);
  while (iVar3 != 0) {
    bVar1 = pbVar4[1];
    lVar8 = lVar8 + ((char)*pbVar4 + -0x30);
    uVar6 = (uint)lVar8;
    iVar3 = (int)((ulonglong)lVar8 >> 0x20);
    pbVar4 = pbVar4 + 1;
    if (bVar1 == 0) {
      if (bVar7) {
        lVar8 = CONCAT44(-(iVar3 + (uint)(uVar6 != 0)),-uVar6);
      }
      break;
    }
    lVar8 = _allmul(uVar6,iVar3,10,0);
    iVar3 = isdigit((uint)bVar1);
  }
  *(longlong *)out = lVar8;
  if (local_138[0] == 0x2d) {
    local_144 = local_138 + 1;
  }
  uVar6 = 0xffffffff;
  pbVar4 = local_144;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  if (~uVar6 - 1 < 0x14) {
    return 0;
  }
  uVar6 = 0xffffffff;
  pbVar4 = local_144;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  if (0x14 < ~uVar6 - 1) {
    return 1;
  }
  pcVar5 = "18446744073709551615";
  while( true ) {
    bVar1 = *local_144;
    bVar7 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = local_144[1];
    bVar7 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) break;
    local_144 = local_144 + 2;
    pcVar5 = pcVar5 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  uVar6 = (uint)(bVar7 != 0);
  uVar2 = 1 - bVar7;
  return (uint)(uVar2 != uVar6 && -1 < (int)(uVar2 - uVar6));
}

