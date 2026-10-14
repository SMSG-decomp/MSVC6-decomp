void __thiscall
decl_combine_type_specifiers_long_int
          (c1_u8 int_merged,uint current_code,uint new_code,uint sign_bits)

{
  char *pcVar1;
  char *pcVar2;
  int unaff_EBP;
  int in_stack_00000010;
  
  *(ushort *)(unaff_EBP + 0x40) = (ushort)sign_bits | 0x14;
  *(c1_u8 *)(unaff_EBP + 0x44) = int_merged;
  if (in_stack_00000010 == 0) {
    return;
  }
  pcVar1 = type_keyword_text((ushort)new_code);
  pcVar2 = type_keyword_text((ushort)current_code);
  diag_error(0x278,pcVar2,pcVar1);
  decl_check_illegal_token_pair_fragment();
  return;
}

