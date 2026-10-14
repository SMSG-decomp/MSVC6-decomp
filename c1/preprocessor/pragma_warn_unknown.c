int __cdecl pragma_warn_unknown(c1_token *token)

{
  int iVar1;
  
  diag_warning(4,0x44);
  pragma_skip_to_dash(token);
  iVar1 = pragma_dispatch_return_zero_tail();
  return iVar1;
}

