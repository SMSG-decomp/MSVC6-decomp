int __cdecl pragma_dispatch_fragment(void)

{
  int iVar1;
  
  if (g_pch_written == '\0') {
    pch_set_name(g_create_pch_header_name);
    return (int)g_token_pch_creation_point;
  }
  if (g_include_depth == 0) {
    if (g_pch_directive_mode != 1) {
      iVar1 = pragma_dispatch_return_zero_tail();
      return iVar1;
    }
    if (g_pch_include_count[0] == 0) {
      return (int)g_token_pch_creation_point;
    }
  }
  return 0;
}

