ulonglong __cdecl
conv_warn_cast_truncates_2
          (uint lo,int hi,c1_type *source_type,int value_high,char op,int target_size,c1_type *type)

{
  ushort uVar1;
  int iVar2;
  uint size;
  int target_unsigned;
  longlong lVar3;
  ulonglong uVar4;
  
  if (op == 'd') {
    diag_warning(4,0x136);
  }
  else {
    diag_warning(2,0x135);
  }
  uVar1 = source_type->code;
  if ((uVar1 & 0x2000) == 0) {
    if ((((g_ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) && ((uVar1 & 0x1000) == 0)) &&
       (g_opt_J_unsigned_char != '\0')) {
      uVar4 = conv_truncate_constant_to_type(lo,hi,source_type,value_high,op,target_size,type);
      return uVar4;
    }
    iVar2 = type_size_scalar(source_type);
    lVar3 = _allshl(('\b' - (char)iVar2) * '\b',lo,hi);
    iVar2 = type_size_scalar(source_type);
    uVar4 = _allshr(('\b' - (char)iVar2) * '\b',(int)((ulonglong)lVar3 >> 0x20),(uint)lVar3);
  }
  else {
    iVar2 = type_size_scalar(source_type);
    lVar3 = _allshl(('\b' - (char)iVar2) * '\b',lo,hi);
    iVar2 = type_size_scalar(source_type);
    uVar4 = _aullshr(('\b' - (char)iVar2) * '\b',(uint)((ulonglong)lVar3 >> 0x20),(uint)lVar3);
  }
  uVar1 = source_type->code;
  if ((uVar1 & 0x2000) == 0) {
    if (((g_ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) &&
       (((uVar1 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) {
      uVar4 = conv_warn_cast_truncates_constant
                        ((uint)(uVar4 >> 0x20),'\0',lo,(uint)uVar4,value_high,op,target_size,type);
      return uVar4;
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
  size = type_size_scalar(type);
  iVar2 = conv_constant_out_of_range(size,target_unsigned,iVar2,(uint)uVar4,(uint)(uVar4 >> 0x20));
  if (iVar2 != 0) {
    if (op == 'd') {
      diag_warning(4,0x136);
    }
    else {
      diag_warning(2,0x135);
    }
  }
  switch(target_size) {
  case 2:
    break;
  default:
    uVar1 = type->code;
    if (((uVar1 & 0x2000) == 0) &&
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      return (ulonglong)(int)(char)lo;
    }
    return (ulonglong)(lo & 0xff);
  case 4:
    uVar1 = type->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
        (g_opt_J_unsigned_char == '\0')))) {
      return (ulonglong)(int)lo;
    }
    return (ulonglong)lo;
  case 8:
    return CONCAT44(value_high,lo);
  case 0x10:
    return CONCAT44(value_high,lo);
  }
  uVar1 = type->code;
  if (((uVar1 & 0x2000) == 0) &&
     (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
      (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
    return CONCAT44((int)(lo << 0x10) >> 0x1f,(int)(lo << 0x10) >> 0x10);
  }
  return (ulonglong)(lo & 0xffff);
}

