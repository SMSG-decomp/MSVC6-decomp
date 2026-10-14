char __cdecl pragma_expect_dash_token(void)

{
  uchar *puVar1;
  
  puVar1 = pragma_warn_expected_token('-');
  if (puVar1 != (uchar *)0x0) {
    return '\x01';
  }
  token_next((c1_token_reader *)&g_token_position);
  return '\0';
}

