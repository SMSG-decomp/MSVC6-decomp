void decl_check_illegal_token_pair(undefined4 code,undefined4 code2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = type_keyword_text((ushort)code2);
  pcVar2 = type_keyword_text((ushort)code);
  diag_error(0x278,pcVar2,pcVar1);
  decl_check_illegal_token_pair_fragment();
  return;
}

