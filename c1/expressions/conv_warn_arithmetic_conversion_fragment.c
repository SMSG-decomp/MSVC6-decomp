void __cdecl
conv_warn_arithmetic_conversion_fragment
          (ushort code,char ms_extensions,uint lo,uint hi,c1_type *target,int op,c1_type *type)

{
  int iVar1;
  uint size;
  int source_unsigned;
  
  if (((code & 0x2000) == 0) &&
     ((((ms_extensions != '\0' || ((code & 0xfff) != 0x11)) || ((code & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  source_unsigned = 1;
  size = type_size_scalar(target);
  iVar1 = conv_constant_out_of_range(size,iVar1,source_unsigned,lo,hi);
  if (iVar1 != 0) {
    diag_warning(2,0x131,op,type,target);
    return;
  }
  return;
}

