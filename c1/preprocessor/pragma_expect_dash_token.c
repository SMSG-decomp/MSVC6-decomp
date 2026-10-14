char __cdecl pragma_expect_dash_token(void)

{
  c1_token *pcVar1;
  
  pcVar1 = pragma_warn_expected_token('-');
  if (pcVar1 != (c1_token *)0x0) {
    return '\x01';
  }
  token_next(&g_token_position);
  return '\0';
}

