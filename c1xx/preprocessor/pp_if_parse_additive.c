void * __cdecl pp_if_parse_additive(void)

{
  c1_pp_value *left;
  int iVar1;
  c1_pp_value *pcVar2;
  
  left = pp_if_parse_multiplicative();
  while( true ) {
    while( true ) {
      iVar1 = pp_if_accept_token(0x51);
      if (iVar1 == 0) break;
      pcVar2 = pp_if_parse_multiplicative();
      left = pp_if_fold_operator(0x51,left,pcVar2);
    }
    iVar1 = pp_if_accept_token(0x46);
    if (iVar1 == 0) break;
    pcVar2 = pp_if_parse_multiplicative();
    left = pp_if_fold_operator(0x46,left,pcVar2);
  }
  return left;
}

