c1_token * __cdecl pragma_parse_identifier(int kind)

{
  uchar want;
  c1_token *pcVar1;
  c1_token *pcVar2;
  
  pcVar1 = pragma_warn_expected_token('v');
  if (pcVar1 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar1 = token_next(&g_token_position);
  if (pcVar1->code == '~') {
    return (c1_token *)0x0;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar1);
  want = (uchar)kind;
  if (want == '\x01') {
    pcVar1 = pragma_check_on_off();
  }
  else if (want == '\a') {
    pcVar1 = pragma_string_argument();
  }
  else {
    pcVar1 = pragma_warn_expected_token(want);
  }
  if (pcVar1 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar2 = pragma_warn_expected_token('~');
  return (c1_token *)(-(uint)(pcVar2 != (c1_token *)0x0) & (uint)pcVar1);
}

