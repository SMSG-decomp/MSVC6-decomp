c1_pp_value * __cdecl pp_if_fold_operator(byte op,c1_pp_value *left,c1_pp_value *right)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  c1_u32 cVar6;
  bool bVar7;
  uint uVar8;
  char cVar9;
  ushort uVar10;
  longlong lVar11;
  longlong shifted;
  longlong shifted_3;
  longlong shifted_2;
  
  uVar2 = left->type;
  uVar8 = (uint)uVar2;
  uVar10 = uVar2 & 0x2000;
  if ((uVar10 == 0) && ((right == (c1_pp_value *)0x0 || ((right->type & 0x2000) == 0)))) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if ((right == (c1_pp_value *)0x0) ||
     (cVar9 = (&g_type_rank_table)[(byte)right->type & 0xf],
     cVar9 <= (char)(&g_type_rank_table)[uVar8 & 0xf])) {
    cVar9 = (&g_type_rank_table)[uVar8 & 0xf];
  }
  if (cVar9 == '\x01') {
    bVar7 = false;
  }
  switch(op) {
  case 0x31:
    uVar8 = (right->value).hi;
    (left->value).lo = (left->value).lo & (right->value).lo;
    (left->value).hi = (left->value).hi & uVar8;
    break;
  case 0x32:
    if (((left->value).lo != 0 || (left->value).hi != 0) &&
       ((right->value).lo != 0 || (right->value).hi != 0)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1044d2f7;
  case 0x39:
    uVar8 = (right->value).lo;
    uVar4 = (right->value).hi;
    if (uVar8 == 0 && uVar4 == 0) {
LAB_1045791f:
      if (g_pp_if_suppress_depth == 0) {
        diag_error(0x7c);
      }
      break;
    }
    if (bVar7) {
      shifted_3 = _aulldiv((left->value).lo,(left->value).hi,uVar8,uVar4);
      (left->value).lo = (c1_u32)shifted_3;
      shifted._4_4_ = (int)((ulonglong)shifted_3 >> 0x20);
    }
    else {
      lVar11 = _alldiv((left->value).lo,(left->value).hi,uVar8,uVar4);
      shifted._4_4_ = (int)((ulonglong)lVar11 >> 0x20);
      (left->value).lo = (c1_u32)lVar11;
    }
    goto LAB_104577fa;
  case 0x3b:
    if (((left->value).lo == (right->value).lo) && ((left->value).hi == (right->value).hi)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1044d2f7;
  case 0x3c:
    if ((left->value).lo == 0 && (left->value).hi == 0) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1044d2f7;
  case 0x3e:
    if (bVar7) {
      uVar8 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar4 <= uVar8) {
        if (uVar8 <= uVar4) goto LAB_1044d31e;
        goto LAB_1044d327;
      }
    }
    else {
      iVar5 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar3 <= iVar5) {
        if (iVar5 <= iVar3) {
LAB_1044d31e:
          if ((left->value).lo <= (right->value).lo) goto LAB_1044d2f7;
        }
LAB_1044d327:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1044d2f7;
  case 0x3f:
    if (bVar7) {
      uVar8 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar4 <= uVar8) {
        if (uVar8 <= uVar4) goto LAB_1044d382;
        goto LAB_1044d38f;
      }
    }
    else {
      iVar5 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar3 <= iVar5) {
        if (iVar5 <= iVar3) {
LAB_1044d382:
          if ((left->value).lo < (right->value).lo) goto LAB_1044d2f7;
        }
LAB_1044d38f:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1044d2f7;
  case 0x43:
    if ((uVar10 == 0) &&
       (((g_opt_J_unsigned_char == '\0' || ((uVar8 & 0xfff) != 0x11)) || ((uVar2 & 0x1000) != 0))))
    {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    lVar11 = _allshl((byte)(right->value).lo,(left->value).lo,(left->value).hi);
    shifted._4_4_ = (int)((ulonglong)lVar11 >> 0x20);
    (left->value).lo = (c1_u32)lVar11;
    goto LAB_104577fa;
  case 0x44:
    if (bVar7) {
      uVar8 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar8 <= uVar4) {
        if (uVar4 <= uVar8) goto LAB_1044d2ea;
        goto LAB_1045775f;
      }
    }
    else {
      iVar5 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar5 <= iVar3) {
        if (iVar3 <= iVar5) {
LAB_1044d2ea:
          if ((right->value).lo <= (left->value).lo) goto LAB_1044d2f7;
        }
LAB_1045775f:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1044d2f7;
  case 0x45:
    if (bVar7) {
      uVar8 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar8 <= uVar4) {
        if (uVar4 <= uVar8) goto LAB_1044d34e;
        goto LAB_1044d357;
      }
    }
    else {
      iVar5 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar5 <= iVar3) {
        if (iVar3 <= iVar5) {
LAB_1044d34e:
          if ((right->value).lo < (left->value).lo) goto LAB_1044d2f7;
        }
LAB_1044d357:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1044d2f7;
  case 0x46:
    uVar8 = (right->value).lo;
    uVar4 = (left->value).lo;
    (left->value).lo = uVar4 - uVar8;
    piVar1 = &(left->value).hi;
    *piVar1 = (*piVar1 - (right->value).hi) - (uint)(uVar4 < uVar8);
    break;
  case 0x48:
    uVar8 = (right->value).lo;
    uVar4 = (right->value).hi;
    if (uVar8 == 0 && uVar4 == 0) goto LAB_1045791f;
    if (bVar7) {
      shifted_2 = _aullrem((left->value).lo,(left->value).hi,uVar8,uVar4);
      (left->value).lo = (c1_u32)shifted_2;
      shifted._4_4_ = (int)((ulonglong)shifted_2 >> 0x20);
    }
    else {
      lVar11 = _allrem((left->value).lo,(left->value).hi,uVar8,uVar4);
      shifted._4_4_ = (int)((ulonglong)lVar11 >> 0x20);
      (left->value).lo = (c1_u32)lVar11;
    }
    goto LAB_104577fa;
  case 0x4a:
    lVar11 = _allmul((right->value).lo,(right->value).hi,(left->value).lo,(left->value).hi);
    shifted._4_4_ = (int)((ulonglong)lVar11 >> 0x20);
    (left->value).lo = (c1_u32)lVar11;
    goto LAB_104577fa;
  case 0x4c:
    if (((left->value).lo != (right->value).lo) || ((left->value).hi != (right->value).hi)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
LAB_1044d2f7:
    bVar7 = false;
    (left->value).lo = 0;
    (left->value).hi = 0;
    break;
  case 0x4d:
    uVar8 = (right->value).hi;
    (left->value).lo = (left->value).lo | (right->value).lo;
    (left->value).hi = (left->value).hi | uVar8;
    break;
  case 0x4f:
    if (((left->value).lo == 0 && (left->value).hi == 0) &&
       ((right->value).lo == 0 && (right->value).hi == 0)) {
      bVar7 = false;
      (left->value).lo = 0;
      (left->value).hi = 0;
    }
    else {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
    }
    break;
  case 0x51:
    uVar8 = (right->value).lo;
    uVar4 = (left->value).lo;
    iVar5 = (right->value).hi;
    (left->value).lo = uVar4 + uVar8;
    (left->value).hi = (left->value).hi + iVar5 + (uint)CARRY4(uVar4,uVar8);
    break;
  case 0x58:
    if ((uVar10 == 0) &&
       (((g_opt_J_unsigned_char == '\0' || ((uVar8 & 0xfff) != 0x11)) || ((uVar2 & 0x1000) != 0))))
    {
      bVar7 = false;
      lVar11 = _allshr((byte)(right->value).lo,(left->value).hi,(left->value).lo);
      shifted._4_4_ = (int)((ulonglong)lVar11 >> 0x20);
      (left->value).lo = (c1_u32)lVar11;
    }
    else {
      bVar7 = true;
      shifted = _aullshr((byte)(right->value).lo,(left->value).hi,(left->value).lo);
      shifted._4_4_ = (int)((ulonglong)shifted >> 0x20);
      (left->value).lo = (c1_u32)shifted;
    }
    goto LAB_104577fa;
  case 0x59:
    (left->value).lo = ~(left->value).lo;
    (left->value).hi = ~(left->value).hi;
    break;
  case 0x5a:
    cVar6 = (left->value).lo;
    (left->value).lo = -cVar6;
    shifted._4_4_ = -((left->value).hi + (uint)(cVar6 != 0));
LAB_104577fa:
    (left->value).hi = shifted._4_4_;
    break;
  case 0x5b:
    (left->value).lo = (left->value).lo ^ (right->value).lo;
    piVar1 = &(left->value).hi;
    *piVar1 = *piVar1 ^ (right->value).hi;
  }
  left->type = 0x14;
  if (bVar7) {
    left->type = 0x2014;
  }
  return left;
}

