void * __cdecl pp_if_parse_shift(void)

{
  c1_pp_value *pcVar1;
  int iVar2;
  c1_pp_value *pcVar3;
  
  pcVar1 = pp_if_parse_additive();
  iVar2 = pp_if_accept_token(0x58);
  if (iVar2 != 0) {
    pcVar3 = pp_if_parse_additive();
    pcVar1 = pp_if_fold_operator(0x58,pcVar1,pcVar3);
    return pcVar1;
  }
  iVar2 = pp_if_accept_token(0x43);
  if (iVar2 == 0) {
    return pcVar1;
  }
  pcVar3 = pp_if_parse_additive();
  pcVar1 = pp_if_fold_operator(0x43,pcVar1,pcVar3);
  return pcVar1;
}

