ulonglong __cdecl conv_cast_constant_fragment(uint lo,c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    return CONCAT44((int)(lo << 0x10) >> 0x1f,(int)(lo << 0x10) >> 0x10);
  }
  return (ulonglong)(lo & 0xffff);
}

