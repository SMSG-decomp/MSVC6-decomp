fe_pp_value * __cdecl pp_if_parse_bit_xor(void)

{
  fe_pp_value *right;
  int iVar1;
  fe_pp_value *left;
  
  right = pp_if_parse_bit_and();
  iVar1 = pp_if_accept_token(0x5b);
  while (iVar1 != 0) {
    left = pp_if_parse_bit_and();
    right = pp_if_fold_operator(0x5b,left,right);
    iVar1 = pp_if_accept_token(0x5b);
  }
  return right;
}

