uint32_t encode_imm_or_disp_case_151
                   (int value,int field_offset,c2_fe_symbol *target,int size,uint32_t op,
                   uint32_t s_bit,int allow_sign_extend)

{
  int iVar1;
  
  (*g_writer_reloc_type9_hook)(field_offset,target);
  if ((((allow_sign_extend == 0) || (size < 2)) || (op != 0x146)) ||
     (iVar1 = fits_signed_imm8(value), iVar1 == 0)) {
    if (size == 6) {
      emit_value_bytes(0,2);
      size = 4;
    }
  }
  else {
    size = 1;
    s_bit = 2;
  }
  emit_value_bytes(value,size);
  return s_bit;
}

