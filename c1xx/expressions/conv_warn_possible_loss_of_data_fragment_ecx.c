void __cdecl
conv_warn_possible_loss_of_data_fragment_ecx
          (ushort target_code,char opt_J_unsigned_char,uint const_hi,uint const_lo,c1_type *target,
          uint op,c1_type *source_type)

{
  int iVar1;
  uint size;
  int source_unsigned;
  
  if ((target_code & 0x2000) == 0) {
    if ((((target_code & 0xfff) == 0x11) && ((target_code & 0x1000) == 0)) &&
       (opt_J_unsigned_char != '\0')) {
      conv_warn_possible_loss_of_data_fragment_eax(1,const_hi,const_lo,target,op,source_type);
      return;
    }
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  source_unsigned = 1;
  size = type_size_scalar(target);
  iVar1 = conv_constant_out_of_range(size,iVar1,source_unsigned,const_lo,const_hi);
  if (iVar1 == 0) {
    return;
  }
  diag_warning(2,0x131,op,source_type,target);
  return;
}

