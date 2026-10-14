void * __cdecl pp_if_parse_bit_or(void)

{
  c1_pp_value *right;
  int iVar1;
  c1_pp_value *left;
  
  right = pp_if_parse_bit_xor();
  iVar1 = pp_if_accept_token(0x4d);
  while (iVar1 != 0) {
    left = pp_if_parse_bit_xor();
    right = pp_if_fold_operator(0x4d,left,right);
    iVar1 = pp_if_accept_token(0x4d);
  }
  return right;
}

