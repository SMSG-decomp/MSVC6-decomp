void __cdecl pragma_hdrstop(char **name)

{
  c1_token *token;
  byte *text;
  int iVar1;
  byte *pbVar2;
  
  token = token_next(&g_token_position);
  if (token->code == '-') {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
    return;
  }
  if (token->code == 'v') {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x2000;
    token = token_next(&g_token_position);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
    if (token->code == '\a') {
      if ((name != (char **)0x0) && (*name == (char *)0x0)) {
        text = (byte *)_strdup((token->value).string.text);
        iVar1 = isspace((uint)*text);
        while (iVar1 != 0) {
          text = text + 1;
          iVar1 = isspace((uint)*text);
        }
        pbVar2 = str_find_trailing_space(text,(byte *)0x0);
        *pbVar2 = 0;
        *name = (char *)text;
      }
      token = token_next(&g_token_position);
      if (token->code == '~') {
        return;
      }
    }
    else if (token->code == '~') {
      return;
    }
  }
  diag_error(0x356);
  pragma_skip_to_dash(token);
  return;
}

