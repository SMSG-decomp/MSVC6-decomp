fe_pp_value * __cdecl pp_if_parse_relational(void)

{
  fe_pp_value *pfVar1;
  int iVar2;
  fe_pp_value *pfVar3;
  
  pfVar1 = pp_if_parse_shift();
  iVar2 = pp_if_accept_token(0x44);
  if (iVar2 != 0) {
    pfVar3 = pp_if_parse_shift();
    pfVar1 = pp_if_fold_operator(0x44,pfVar1,pfVar3);
    return pfVar1;
  }
  iVar2 = pp_if_accept_token(0x3e);
  if (iVar2 != 0) {
    pfVar3 = pp_if_parse_shift();
    pfVar1 = pp_if_fold_operator(0x3e,pfVar1,pfVar3);
    return pfVar1;
  }
  iVar2 = pp_if_accept_token(0x45);
  if (iVar2 != 0) {
    pfVar3 = pp_if_parse_shift();
    pfVar1 = pp_if_fold_operator(0x45,pfVar1,pfVar3);
    return pfVar1;
  }
  iVar2 = pp_if_accept_token(0x3f);
  if (iVar2 == 0) {
    return pfVar1;
  }
  pfVar3 = pp_if_parse_shift();
  pfVar1 = pp_if_fold_operator(0x3f,pfVar1,pfVar3);
  return pfVar1;
}

