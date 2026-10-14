void __cdecl
conv_warn_constant_conversion
          (uint source_code,uint target_code,char ms_extensions,uint lo,uint hi,c1_type *source_type
          ,int op,c1_type *type)

{
  ushort code;
  ushort uVar1;
  int target_unsigned;
  uint size;
  int iVar2;
  
  if (((((target_code & 0xfff) == 0x11) && ((target_code & 0x1000) == 0)) &&
      (g_opt_J_unsigned_char != '\0')) &&
     (((source_code & 0x2000) == 0 &&
      ((((ms_extensions != '\0' || ((source_code & 0xfff) != 0x11)) ||
        (((source_code & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))) &&
       (((int)hi < 1 && ((int)hi < 0)))))))) {
    diag_warning(4,0xf5,op,type,source_type);
    ms_extensions = g_ms_extensions;
  }
  code = source_type->code;
  uVar1 = type->code;
  if (code != uVar1) {
    if ((uVar1 & 0x2000) == 0) {
      if ((((ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) && ((uVar1 & 0x1000) == 0)) &&
         (g_opt_J_unsigned_char != '\0')) {
        conv_warn_arithmetic_conversion_fragment(code,'\0',lo,hi,source_type,op,type);
        return;
      }
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    if (((code & 0x2000) == 0) &&
       (((ms_extensions != '\0' || ((code & 0xfff) != 0x11)) ||
        (((code & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
      target_unsigned = 0;
    }
    else {
      target_unsigned = 1;
    }
    size = type_size_scalar(source_type);
    iVar2 = conv_constant_out_of_range(size,target_unsigned,iVar2,lo,hi);
    if (iVar2 != 0) {
      diag_warning(2,0x131,op,type,source_type);
      return;
    }
  }
  return;
}

