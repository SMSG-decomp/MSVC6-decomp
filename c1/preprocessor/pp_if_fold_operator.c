fe_pp_value * __cdecl pp_if_fold_operator(byte op,fe_pp_value *left,fe_pp_value *right)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  bool bVar7;
  ushort uVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  uint64_t uVar14;
  
  uVar2 = left->type;
  uVar11 = (uint)uVar2;
  uVar8 = uVar2 & 0x2000;
  if ((uVar8 == 0) && ((right == (fe_pp_value *)0x0 || ((right->type & 0x2000) == 0)))) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  if ((right == (fe_pp_value *)0x0) ||
     (cVar9 = (&g_type_rank_table)[(byte)right->type & 0xf],
     cVar9 <= (char)(&g_type_rank_table)[uVar11 & 0xf])) {
    cVar9 = (&g_type_rank_table)[uVar11 & 0xf];
  }
  if (cVar9 == '\x01') {
    bVar7 = false;
  }
  switch(op) {
  case 0x31:
    uVar11 = (right->value).hi;
    (left->value).lo = (left->value).lo & (right->value).lo;
    (left->value).hi = (left->value).hi & uVar11;
    break;
  case 0x32:
    if (((left->value).lo != 0 || (left->value).hi != 0) &&
       ((right->value).lo != 0 || (right->value).hi != 0)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1060b8ff;
  case 0x39:
    uVar5 = (right->value).lo;
    uVar6 = (right->value).hi;
    if (uVar5 == 0 && uVar6 == 0) {
LAB_10626c53:
      if (g_pp_if_suppress_depth == 0) {
        diag_error(0x7c);
      }
      break;
    }
    if (bVar7) {
      uVar14 = _aulldiv((left->value).lo,(left->value).hi,uVar5,uVar6);
      iVar10 = (int)(uVar14 >> 0x20);
      (left->value).lo = (uint)uVar14;
    }
    else {
      uVar14 = _alldiv((left->value).lo,(left->value).hi,uVar5,uVar6);
      iVar10 = (int)(uVar14 >> 0x20);
      (left->value).lo = (uint)uVar14;
    }
    goto LAB_1060baaf;
  case 0x3b:
    if (((left->value).lo == (right->value).lo) && ((left->value).hi == (right->value).hi)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1060b8ff;
  case 0x3c:
    if ((left->value).lo == 0 && (left->value).hi == 0) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
    goto LAB_1060b8ff;
  case 0x3e:
    if (bVar7) {
      uVar11 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar4 <= uVar11) {
        if (uVar11 <= uVar4) goto LAB_1060b9ef;
        goto LAB_1060b9fc;
      }
    }
    else {
      iVar10 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar3 <= iVar10) {
        if (iVar10 <= iVar3) {
LAB_1060b9ef:
          if ((left->value).lo <= (right->value).lo) goto LAB_1060b8ff;
        }
LAB_1060b9fc:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1060b8ff;
  case 0x3f:
    if (bVar7) {
      uVar11 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar4 <= uVar11) {
        if (uVar11 <= uVar4) goto LAB_1060ba65;
        goto LAB_1060ba72;
      }
    }
    else {
      iVar10 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar3 <= iVar10) {
        if (iVar10 <= iVar3) {
LAB_1060ba65:
          if ((left->value).lo < (right->value).lo) goto LAB_1060b8ff;
        }
LAB_1060ba72:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1060b8ff;
  case 0x43:
    if ((uVar8 == 0) &&
       ((((g_ms_extensions != '\0' || (g_opt_J_unsigned_char == '\0')) || ((uVar11 & 0xfff) != 0x11)
         ) || ((uVar2 & 0x1000) != 0)))) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    lVar12 = _allshl((byte)(right->value).lo,(left->value).lo,(left->value).hi);
    iVar10 = (int)((ulonglong)lVar12 >> 0x20);
    (left->value).lo = (uint)lVar12;
    goto LAB_1060baaf;
  case 0x44:
    if (bVar7) {
      uVar11 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar11 <= uVar4) {
        if (uVar4 <= uVar11) goto LAB_1060b9b4;
        goto LAB_1060b9c1;
      }
    }
    else {
      iVar10 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar10 <= iVar3) {
        if (iVar3 <= iVar10) {
LAB_1060b9b4:
          if ((right->value).lo <= (left->value).lo) goto LAB_1060b8ff;
        }
LAB_1060b9c1:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1060b8ff;
  case 0x45:
    if (bVar7) {
      uVar11 = (left->value).hi;
      uVar4 = (right->value).hi;
      if (uVar11 <= uVar4) {
        if (uVar4 <= uVar11) goto LAB_1060ba2a;
        goto LAB_1060ba37;
      }
    }
    else {
      iVar10 = (left->value).hi;
      iVar3 = (right->value).hi;
      if (iVar10 <= iVar3) {
        if (iVar3 <= iVar10) {
LAB_1060ba2a:
          if ((right->value).lo < (left->value).lo) goto LAB_1060b8ff;
        }
LAB_1060ba37:
        bVar7 = false;
        (left->value).lo = 1;
        (left->value).hi = 0;
        break;
      }
    }
    goto LAB_1060b8ff;
  case 0x46:
    uVar11 = (right->value).lo;
    uVar4 = (left->value).lo;
    (left->value).lo = uVar4 - uVar11;
    piVar1 = &(left->value).hi;
    *piVar1 = (*piVar1 - (right->value).hi) - (uint)(uVar4 < uVar11);
    break;
  case 0x48:
    uVar5 = (right->value).lo;
    uVar6 = (right->value).hi;
    if (uVar5 == 0 && uVar6 == 0) goto LAB_10626c53;
    if (bVar7) {
      uVar14 = _aullrem((left->value).lo,(left->value).hi,uVar5,uVar6);
      iVar10 = (int)(uVar14 >> 0x20);
      (left->value).lo = (uint)uVar14;
    }
    else {
      lVar12 = _allrem((left->value).lo,(left->value).hi,uVar5,uVar6);
      iVar10 = (int)((ulonglong)lVar12 >> 0x20);
      (left->value).lo = (uint)lVar12;
    }
    goto LAB_1060baaf;
  case 0x4a:
    lVar12 = _allmul((right->value).lo,(right->value).hi,(left->value).lo,(left->value).hi);
    iVar10 = (int)((ulonglong)lVar12 >> 0x20);
    (left->value).lo = (uint)lVar12;
    goto LAB_1060baaf;
  case 0x4c:
    if (((left->value).lo != (right->value).lo) || ((left->value).hi != (right->value).hi)) {
      bVar7 = false;
      (left->value).lo = 1;
      (left->value).hi = 0;
      break;
    }
LAB_1060b8ff:
    bVar7 = false;
    (left->value).lo = 0;
    (left->value).hi = 0;
    break;
  case 0x4d:
    uVar11 = (right->value).hi;
    (left->value).lo = (left->value).lo | (right->value).lo;
    (left->value).hi = (left->value).hi | uVar11;
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
    uVar11 = (right->value).lo;
    uVar4 = (left->value).lo;
    iVar10 = (right->value).hi;
    (left->value).lo = uVar4 + uVar11;
    (left->value).hi = (left->value).hi + iVar10 + (uint)CARRY4(uVar4,uVar11);
    break;
  case 0x58:
    if ((uVar8 == 0) &&
       ((((g_ms_extensions != '\0' || (g_opt_J_unsigned_char == '\0')) || ((uVar11 & 0xfff) != 0x11)
         ) || ((uVar2 & 0x1000) != 0)))) {
      bVar7 = false;
      lVar12 = _allshr((byte)(right->value).lo,(left->value).hi,(left->value).lo);
      iVar10 = (int)((ulonglong)lVar12 >> 0x20);
      (left->value).lo = (uint)lVar12;
    }
    else {
      bVar7 = true;
      uVar13 = _aullshr((byte)(right->value).lo,(left->value).hi,(left->value).lo);
      iVar10 = (int)(uVar13 >> 0x20);
      (left->value).lo = (uint)uVar13;
    }
    goto LAB_1060baaf;
  case 0x59:
    (left->value).lo = ~(left->value).lo;
    (left->value).hi = ~(left->value).hi;
    break;
  case 0x5a:
    uVar11 = (left->value).lo;
    (left->value).lo = -uVar11;
    iVar10 = -((left->value).hi + (uint)(uVar11 != 0));
LAB_1060baaf:
    (left->value).hi = iVar10;
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

