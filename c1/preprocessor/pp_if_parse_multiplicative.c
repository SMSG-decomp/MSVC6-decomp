fe_pp_value * __cdecl pp_if_parse_multiplicative(void)

{
  fe_pp_value *left;
  int iVar1;
  fe_pp_value *pfVar2;
  
  left = pp_if_parse_primary();
  while( true ) {
    while( true ) {
      while( true ) {
        iVar1 = pp_if_accept_token(0x4a);
        if (iVar1 == 0) break;
        pfVar2 = pp_if_parse_primary();
        left = pp_if_fold_operator(0x4a,left,pfVar2);
      }
      iVar1 = pp_if_accept_token(0x39);
      if (iVar1 == 0) break;
      pfVar2 = pp_if_parse_primary();
      left = pp_if_fold_operator(0x39,left,pfVar2);
    }
    iVar1 = pp_if_accept_token(0x48);
    if (iVar1 == 0) break;
    pfVar2 = pp_if_parse_primary();
    left = pp_if_fold_operator(0x48,left,pfVar2);
  }
  return left;
}

