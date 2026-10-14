void __cdecl
conv_warn_constant_conversion
          (uint const_hi,uint const_lo,c1_type *target,uint op,c1_type *source_type)

{
  ushort target_code;
  ushort uVar1;
  int target_unsigned;
  uint size;
  int iVar2;
  
  diag_warning(4,0xf5,op,source_type,target);
  target_code = target->code;
  uVar1 = source_type->code;
  if (target_code != uVar1) {
    if ((uVar1 & 0x2000) == 0) {
      if ((((uVar1 & 0xfff) == 0x11) && ((uVar1 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))
      {
        conv_warn_possible_loss_of_data_fragment_ecx
                  (target_code,g_opt_J_unsigned_char,const_hi,const_lo,target,op,source_type);
        return;
      }
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    if ((target_code & 0x2000) == 0) {
      if ((((target_code & 0xfff) == 0x11) && ((target_code & 0x1000) == 0)) &&
         (g_opt_J_unsigned_char != '\0')) {
        conv_warn_possible_loss_of_data_fragment_eax(iVar2,const_hi,const_lo,target,op,source_type);
        return;
      }
      target_unsigned = 0;
    }
    else {
      target_unsigned = 1;
    }
    size = type_size_scalar(target);
    iVar2 = conv_constant_out_of_range(size,target_unsigned,iVar2,const_lo,const_hi);
    if (iVar2 != 0) {
      diag_warning(2,0x131,op,source_type,target);
      return;
    }
  }
  return;
}

