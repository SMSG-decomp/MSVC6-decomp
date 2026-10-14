void __cdecl
conv_warn_possible_loss_of_data_fragment_eax
          (int source_unsigned,uint const_hi,uint const_lo,c1_type *target,uint op,
          c1_type *source_type)

{
  uint size;
  uint source_unsigned_00;
  int iVar1;
  
  source_unsigned_00 = source_unsigned & 0xff;
  iVar1 = 1;
  size = type_size_scalar(target);
  iVar1 = conv_constant_out_of_range(size,iVar1,source_unsigned_00,const_lo,const_hi);
  if (iVar1 == 0) {
    return;
  }
  diag_warning(2,0x131,op,source_type,target);
  return;
}

