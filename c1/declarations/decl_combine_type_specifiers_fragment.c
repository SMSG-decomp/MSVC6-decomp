void __cdecl
decl_combine_type_specifiers_fragment(c1_u8 size_keyword,uint code,c1_specifier_state *spec)

{
  char *pcVar1;
  char *pcVar2;
  ushort unaff_BX;
  ushort unaff_DI;
  int in_stack_00000010;
  
  spec->basic_type = (ushort)code | 0x14;
  spec->size_keyword = size_keyword;
  if (in_stack_00000010 == 0) {
    return;
  }
  pcVar1 = type_keyword_text(unaff_DI);
  pcVar2 = type_keyword_text(unaff_BX);
  diag_error(0x278,pcVar2,pcVar1);
  decl_check_illegal_token_pair_fragment();
  return;
}

