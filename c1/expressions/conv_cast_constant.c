ulonglong __cdecl conv_cast_constant(char op,int node,c1_type *type)

{
  ushort uVar1;
  uint lo;
  c1_type *type_00;
  int iVar2;
  uint uVar3;
  uint lo_00;
  int target_unsigned;
  uint hi;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  
  iVar2 = node;
  uVar3 = *(uint *)(node + 0x14);
  lo = *(uint *)(node + 0x10);
  uVar1 = type->code;
  if (((char)uVar1 < '\0') && (((uVar1 & 0x8f) == 0x86 || ((uVar1 & 0x8f) == 0x82)))) {
    return *(ulonglong *)(node + 0x10);
  }
  uVar6 = uVar3;
  if ((uVar1 & 0x110) != 0) {
    node = type_size_scalar(type);
  }
  type_00 = *(c1_type **)(iVar2 + 4);
  lo_00 = lo;
  hi = uVar3;
  if (((type_00->code & 0x110) == 0) || (iVar2 = type_size_scalar(type_00), node <= iVar2))
  goto switchD_1061bf5e_caseD_10;
  switch(iVar2) {
  case 2:
    uVar1 = type_00->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      lo_00 = (int)(lo << 0x10) >> 0x10;
      hi = (int)(lo << 0x10) >> 0x1f;
    }
    else {
      lo_00 = lo & 0xffff;
      hi = 0;
    }
    uVar6 = hi;
    if (lo_00 == lo) {
      if (hi != uVar3) {
        uVar5 = conv_warn_cast_truncates_2(lo_00,hi,type_00,hi,op,node,type);
        return uVar5;
      }
      break;
    }
    if (op == 'd') {
      diag_warning(4,0x136);
      break;
    }
    goto LAB_1064ca6b;
  default:
    uVar1 = type_00->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      lo_00 = (uint)(char)lo;
      hi = (int)lo_00 >> 0x1f;
    }
    else {
      lo_00 = lo & 0xff;
      hi = 0;
    }
    uVar6 = hi;
    if (lo_00 == lo) {
      if (hi != uVar3) {
        uVar5 = conv_warn_constant_truncation(lo_00,hi,type_00,hi,op,node,type);
        return uVar5;
      }
      break;
    }
    if (op == 'd') {
      diag_warning(4,0x136);
      break;
    }
LAB_1064ca6b:
    uVar6 = hi;
    diag_warning(2,0x135);
    break;
  case 4:
    uVar1 = type_00->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
        (g_opt_J_unsigned_char == '\0')))) {
      hi = (int)lo >> 0x1f;
    }
    else {
      hi = 0;
    }
    uVar6 = hi;
    if (hi != uVar3) {
      uVar5 = conv_warn_cast_truncates(lo,hi,type_00,hi,op,node,type);
      return uVar5;
    }
    break;
  case 8:
    break;
  case 0x10:
    break;
  }
switchD_1061bf5e_caseD_10:
  uVar1 = type_00->code;
  if ((uVar1 & 0x2000) == 0) {
    if ((((g_ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) && ((uVar1 & 0x1000) == 0)) &&
       (g_opt_J_unsigned_char != '\0')) {
      uVar5 = conv_truncate_constant_to_type(lo_00,hi,type_00,uVar6,op,node,type);
      return uVar5;
    }
    iVar2 = type_size_scalar(type_00);
    lVar4 = _allshl(('\b' - (char)iVar2) * '\b',lo_00,hi);
    iVar2 = type_size_scalar(type_00);
    uVar5 = _allshr(('\b' - (char)iVar2) * '\b',(int)((ulonglong)lVar4 >> 0x20),(uint)lVar4);
  }
  else {
    iVar2 = type_size_scalar(type_00);
    lVar4 = _allshl(('\b' - (char)iVar2) * '\b',lo_00,hi);
    iVar2 = type_size_scalar(type_00);
    uVar5 = _aullshr(('\b' - (char)iVar2) * '\b',(uint)((ulonglong)lVar4 >> 0x20),(uint)lVar4);
  }
  uVar1 = type_00->code;
  if ((uVar1 & 0x2000) == 0) {
    if (((g_ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) &&
       (((uVar1 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) {
      uVar5 = conv_warn_cast_truncates_constant
                        ((uint)(uVar5 >> 0x20),'\0',lo_00,(uint)uVar5,uVar6,op,node,type);
      return uVar5;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  uVar1 = type->code;
  if (((uVar1 & 0x2000) == 0) &&
     (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
      (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
    target_unsigned = 0;
  }
  else {
    target_unsigned = 1;
  }
  uVar3 = type_size_scalar(type);
  iVar2 = conv_constant_out_of_range(uVar3,target_unsigned,iVar2,(uint)uVar5,(uint)(uVar5 >> 0x20));
  if (iVar2 != 0) {
    if (op == 'd') {
      diag_warning(4,0x136);
    }
    else {
      diag_warning(2,0x135);
    }
  }
  switch(node) {
  case 2:
    uVar1 = type->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      return CONCAT44((int)(lo_00 << 0x10) >> 0x1f,(int)(lo_00 << 0x10) >> 0x10);
    }
    return (ulonglong)(lo_00 & 0xffff);
  default:
    uVar1 = type->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      return (ulonglong)(int)(char)lo_00;
    }
    return (ulonglong)(lo_00 & 0xff);
  case 4:
    break;
  case 8:
    return CONCAT44(uVar6,lo_00);
  case 0x10:
    return CONCAT44(uVar6,lo_00);
  }
  uVar1 = type->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    return (ulonglong)(int)lo_00;
  }
  return (ulonglong)lo_00;
}

