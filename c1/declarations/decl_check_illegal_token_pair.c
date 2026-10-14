void decl_check_illegal_token_pair(void)

{
  char *pcVar1;
  char *pcVar2;
  ushort unaff_BX;
  ushort unaff_DI;
  
  pcVar1 = type_keyword_text(unaff_DI);
  pcVar2 = type_keyword_text(unaff_BX);
  diag_error(0x278,pcVar2,pcVar1);
  decl_check_illegal_token_pair_fragment();
  return;
}

