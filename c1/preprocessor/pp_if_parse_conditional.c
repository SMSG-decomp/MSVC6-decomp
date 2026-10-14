fe_pp_value * __cdecl pp_if_parse_conditional(void)

{
  fe_pp_value *pfVar1;
  int iVar2;
  fe_pp_value *pfVar3;
  fe_pp_value *pfVar4;
  
  pfVar1 = pp_if_parse_logical_or();
  iVar2 = pp_if_accept_token(0x56);
  if (iVar2 == 0) {
    return pfVar1;
  }
  pfVar3 = pp_if_parse_logical_or();
  iVar2 = pp_if_accept_token(0x36);
  if (iVar2 == 0) {
    diag_fatal_simple(0x11);
  }
  pfVar4 = pp_if_parse_logical_or();
  if ((pfVar1->value).lo != 0 || (pfVar1->value).hi != 0) {
    pfVar4 = pfVar3;
  }
  return pfVar4;
}

