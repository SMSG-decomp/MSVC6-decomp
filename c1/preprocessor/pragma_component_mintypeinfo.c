void __cdecl pragma_component_mintypeinfo(void)

{
  c1_token *pcVar1;
  
  pcVar1 = token_next(&g_token_position);
  if (pcVar1->code == '7') {
    pcVar1 = pragma_check_on_off();
    if (pcVar1 != (c1_token *)0x0) {
      pragma_warn_expected_token('~');
    }
  }
  else if (pcVar1->code != '~') {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar1);
    pragma_warn_expected_token('7');
    return;
  }
  return;
}

