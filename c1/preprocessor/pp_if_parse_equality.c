fe_pp_value * __cdecl pp_if_parse_equality(void)

{
  fe_pp_value *pfVar1;
  int iVar2;
  fe_pp_value *pfVar3;
  
  pfVar1 = pp_if_parse_relational();
  iVar2 = pp_if_accept_token(0x3b);
  if (iVar2 != 0) {
    pfVar3 = pp_if_parse_relational();
    pfVar1 = pp_if_fold_operator(0x3b,pfVar3,pfVar1);
    return pfVar1;
  }
  iVar2 = pp_if_accept_token(0x4c);
  if (iVar2 == 0) {
    return pfVar1;
  }
  pfVar3 = pp_if_parse_relational();
  pfVar1 = pp_if_fold_operator(0x4c,pfVar3,pfVar1);
  return pfVar1;
}

