void * __cdecl pp_if_parse_logical_or(void)

{
  int iVar1;
  c1_pp_value *left;
  int iVar2;
  c1_pp_value *right;
  
  iVar1 = g_pp_if_suppress_depth;
  left = pp_if_parse_logical_and();
  iVar2 = pp_if_accept_token(0x4f);
  while (iVar2 != 0) {
    if ((left->value).lo != 0 || (left->value).hi != 0) {
      g_pp_if_suppress_depth = g_pp_if_suppress_depth + 1;
    }
    right = pp_if_parse_logical_and();
    left = pp_if_fold_operator(0x4f,left,right);
    iVar2 = pp_if_accept_token(0x4f);
  }
  g_pp_if_suppress_depth = iVar1;
  return left;
}

