ulonglong __cdecl
conv_warn_cast_truncates_constant
          (uint check_hi,char ms_extensions,uint lo,uint check_lo,int value_high,byte op,
          int target_size,c1_type *type)

{
  ushort uVar1;
  uint size;
  int iVar2;
  int source_unsigned;
  
  uVar1 = type->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  source_unsigned = 1;
  size = type_size_scalar(type);
  iVar2 = conv_constant_out_of_range(size,iVar2,source_unsigned,check_lo,check_hi);
  if (iVar2 != 0) {
    if (op == 100) {
      diag_warning(4,0x136);
    }
    else {
      diag_warning(2,0x135,op);
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
       (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
        (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
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
     ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    return CONCAT44((int)(lo << 0x10) >> 0x1f,(int)(lo << 0x10) >> 0x10);
  }
  return (ulonglong)(lo & 0xffff);
}

