void __cdecl pragma_on_off_option(void)

{
  byte *token;
  c1_u8 *pcVar1;
  
  token = token_next((c1_token_reader *)&g_token_position);
  if (*token == 0x37) {
    pcVar1 = pragma_check_on_off();
    if (pcVar1 != (c1_u8 *)0x0) {
      g_pragma_mintypeinfo = pcVar1[8] & 1;
      pragma_warn_expected_token('~');
    }
  }
  else if (*token != 0x7e) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
    pragma_warn_expected_token('7');
    return;
  }
  return;
}

