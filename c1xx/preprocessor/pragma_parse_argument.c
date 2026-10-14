c1xx_token * __cdecl pragma_parse_argument(int kind)

{
  uchar want;
  uchar *puVar1;
  c1_u8 *pcVar2;
  
  puVar1 = pragma_warn_expected_token('v');
  if (puVar1 == (uchar *)0x0) {
    return (c1xx_token *)0x0;
  }
  want = (uchar)kind;
  if (want == '\x01') {
    pcVar2 = pragma_check_on_off();
  }
  else if (want == '\a') {
    pcVar2 = pragma_string_argument();
  }
  else {
    pcVar2 = pragma_warn_expected_token(want);
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    return (c1xx_token *)0x0;
  }
  puVar1 = pragma_warn_expected_token('~');
  return (c1xx_token *)(-(uint)(puVar1 != (uchar *)0x0) & (uint)pcVar2);
}

