int __cdecl pragma_warn_unknown(char *token)

{
  int iVar1;
  
  diag_warning(4,0x44);
  pragma_skip_to_dash((byte *)token);
  iVar1 = pragma_dispatch_return_zero_tail();
  return iVar1;
}

