void * __cdecl pp_if_parse_bit_and(void)

{
  c1_pp_value *right;
  int iVar1;
  c1_pp_value *left;
  
  right = pp_if_parse_equality();
  iVar1 = pp_if_accept_token(0x31);
  while (iVar1 != 0) {
    left = pp_if_parse_equality();
    right = pp_if_fold_operator(0x31,left,right);
    iVar1 = pp_if_accept_token(0x31);
  }
  return right;
}

