int __fastcall
switch_find_dense_prefix
          (c2_switch_case_range *cases,int ncases,int values_covered,uint32_t span_low,
          int32_t span_high)

{
  int iVar1;
  uint uVar2;
  uint b_lo;
  uint a_lo;
  int a_hi;
  int iVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int local_30;
  int local_24;
  uint32_t local_8;
  
  local_8 = 1;
  iVar1 = cases->first_high;
  uVar2 = cases->first;
  local_30 = ncases + -1;
  if (local_30 != 0) {
    b_lo = g_switch_thresholds[g_opt_favor_speed == 0].max_dense_gap;
    uVar5 = uVar2;
    local_24 = iVar1;
    do {
      cases = cases->next;
      a_lo = cases->first;
      a_hi = cases->first_high;
      iVar3 = (a_hi - local_24) - (uint)(a_lo < uVar5);
      if ((-1 < iVar3) && (((0 < iVar3 || (b_lo < a_lo - uVar5)) && (local_30 != 1)))) {
        lVar6 = __allmul(a_lo,a_hi,2,0);
        lVar6 = lVar6 - CONCAT44(local_24,uVar5);
        iVar4 = (int)((ulonglong)lVar6 >> 0x20);
        iVar3 = cases->next->first_high;
        if ((iVar4 < iVar3) || ((iVar4 <= iVar3 && ((uint)lVar6 <= cases->next->first)))) break;
      }
      lVar6 = __allmul(local_8,(int)local_8 >> 0x1f,b_lo,0);
      if (lVar6 < CONCAT44(((a_hi - iVar1) - (uint)(a_lo < uVar2)) +
                           (uint)(0xfffffffe < a_lo - uVar2),(a_lo - uVar2) + 1)) break;
      local_8 = local_8 + 1;
      local_30 = local_30 + -1;
      uVar5 = a_lo;
      local_24 = a_hi;
    } while (local_30 != 0);
  }
  if ((int)local_8 <= (int)g_switch_thresholds[g_opt_favor_speed == 0].min_cases) {
    local_8 = ncases;
  }
  return local_8 + 1;
}

