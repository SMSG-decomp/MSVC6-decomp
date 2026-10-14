fe_pp_value * __cdecl pp_if_parse_shift(void)

{
  fe_pp_value *pfVar1;
  int iVar2;
  fe_pp_value *pfVar3;
  
  pfVar1 = pp_if_parse_additive();
  iVar2 = pp_if_accept_token(0x58);
  if (iVar2 != 0) {
    pfVar3 = pp_if_parse_additive();
    pfVar1 = pp_if_fold_operator(0x58,pfVar1,pfVar3);
    return pfVar1;
  }
  iVar2 = pp_if_accept_token(0x43);
  if (iVar2 == 0) {
    return pfVar1;
  }
  pfVar3 = pp_if_parse_additive();
  pfVar1 = pp_if_fold_operator(0x43,pfVar1,pfVar3);
  return pfVar1;
}

