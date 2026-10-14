void * __cdecl pp_if_parse_equality(void)

{
  c1_pp_value *pcVar1;
  int iVar2;
  c1_pp_value *pcVar3;
  
  pcVar1 = pp_if_parse_relational();
  iVar2 = pp_if_accept_token(0x3b);
  if (iVar2 != 0) {
    pcVar3 = pp_if_parse_relational();
    pcVar1 = pp_if_fold_operator(0x3b,pcVar3,pcVar1);
    return pcVar1;
  }
  iVar2 = pp_if_accept_token(0x4c);
  if (iVar2 == 0) {
    return pcVar1;
  }
  pcVar3 = pp_if_parse_relational();
  pcVar1 = pp_if_fold_operator(0x4c,pcVar3,pcVar1);
  return pcVar1;
}

