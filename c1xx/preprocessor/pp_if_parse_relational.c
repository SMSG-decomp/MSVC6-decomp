void * __cdecl pp_if_parse_relational(void)

{
  c1_pp_value *pcVar1;
  int iVar2;
  c1_pp_value *pcVar3;
  
  pcVar1 = pp_if_parse_shift();
  iVar2 = pp_if_accept_token(0x44);
  if (iVar2 != 0) {
    pcVar3 = pp_if_parse_shift();
    pcVar1 = pp_if_fold_operator(0x44,pcVar1,pcVar3);
    return pcVar1;
  }
  iVar2 = pp_if_accept_token(0x3e);
  if (iVar2 != 0) {
    pcVar3 = pp_if_parse_shift();
    pcVar1 = pp_if_fold_operator(0x3e,pcVar1,pcVar3);
    return pcVar1;
  }
  iVar2 = pp_if_accept_token(0x45);
  if (iVar2 != 0) {
    pcVar3 = pp_if_parse_shift();
    pcVar1 = pp_if_fold_operator(0x45,pcVar1,pcVar3);
    return pcVar1;
  }
  iVar2 = pp_if_accept_token(0x3f);
  if (iVar2 == 0) {
    return pcVar1;
  }
  pcVar3 = pp_if_parse_shift();
  pcVar1 = pp_if_fold_operator(0x3f,pcVar1,pcVar3);
  return pcVar1;
}

