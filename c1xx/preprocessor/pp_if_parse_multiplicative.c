void * __cdecl pp_if_parse_multiplicative(void)

{
  c1_pp_value *left;
  int iVar1;
  c1_pp_value *pcVar2;
  
  left = pp_if_parse_primary();
  while( true ) {
    while( true ) {
      while( true ) {
        iVar1 = pp_if_accept_token(0x4a);
        if (iVar1 == 0) break;
        pcVar2 = pp_if_parse_primary();
        left = pp_if_fold_operator(0x4a,left,pcVar2);
      }
      iVar1 = pp_if_accept_token(0x39);
      if (iVar1 == 0) break;
      pcVar2 = pp_if_parse_primary();
      left = pp_if_fold_operator(0x39,left,pcVar2);
    }
    iVar1 = pp_if_accept_token(0x48);
    if (iVar1 == 0) break;
    pcVar2 = pp_if_parse_primary();
    left = pp_if_fold_operator(0x48,left,pcVar2);
  }
  return left;
}

