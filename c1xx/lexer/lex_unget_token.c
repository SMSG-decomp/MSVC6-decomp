int __cdecl lex_unget_token(c1xx_token *tok)

{
  if (tok != (c1xx_token *)0x0) {
    if ((tok->code == 'v') && (0 < g_paren_depth)) {
      g_paren_depth = g_paren_depth + -1;
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok);
  }
  return 0;
}

