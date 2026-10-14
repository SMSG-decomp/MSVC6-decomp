ulonglong __cdecl
conv_warn_cast_truncates
          (c1_type *src_type,uint value_lo,int value_hi,int value_hi_local,byte op,int target_size,
          c1_type *target)

{
  ushort uVar1;
  int iVar2;
  uint size;
  int target_unsigned;
  longlong lVar3;
  ulonglong uVar4;
  
  if (op == 100) {
    diag_warning(4,0x136);
  }
  else {
    diag_warning(2,0x135);
  }
  uVar1 = src_type->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    iVar2 = type_size_scalar(src_type);
    lVar3 = _allshl(('\b' - (char)iVar2) * '\b',value_lo,value_hi);
    iVar2 = type_size_scalar(src_type);
    uVar4 = _allshr(('\b' - (char)iVar2) * '\b',(int)((ulonglong)lVar3 >> 0x20),(uint)lVar3);
  }
  else {
    iVar2 = type_size_scalar(src_type);
    lVar3 = _allshl(('\b' - (char)iVar2) * '\b',value_lo,value_hi);
    iVar2 = type_size_scalar(src_type);
    uVar4 = _aullshr(('\b' - (char)iVar2) * '\b',(uint)((ulonglong)lVar3 >> 0x20),(uint)lVar3);
  }
  uVar1 = src_type->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  uVar1 = target->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    target_unsigned = 0;
  }
  else {
    target_unsigned = 1;
  }
  size = type_size_scalar(target);
  iVar2 = conv_constant_out_of_range(size,target_unsigned,iVar2,(uint)uVar4,(uint)(uVar4 >> 0x20));
  if (iVar2 != 0) {
    if (op == 100) {
      diag_warning(4,0x136);
    }
    else {
      diag_warning(2,0x135);
    }
  }
  switch(target_size) {
  case 2:
    uVar1 = target->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      return CONCAT44((int)(value_lo << 0x10) >> 0x1f,(int)(value_lo << 0x10) >> 0x10);
    }
    return (ulonglong)(value_lo & 0xffff);
  case 4:
    uVar1 = target->code;
    if (((uVar1 & 0x2000) == 0) &&
       ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))
    {
      return (ulonglong)(int)value_lo;
    }
    return (ulonglong)value_lo;
  case 8:
    return CONCAT44(value_hi_local,value_lo);
  case 0x10:
    return CONCAT44(value_hi_local,value_lo);
  }
  uVar1 = target->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    return (ulonglong)(int)(char)value_lo;
  }
  return (ulonglong)(value_lo & 0xff);
}

