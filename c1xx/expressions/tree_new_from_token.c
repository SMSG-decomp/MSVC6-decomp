char * __cdecl tree_new_from_token(byte *next_token,char *token)

{
  tree_new_type_token_node((c1xx_token *)token,*(c1_type **)(token + 0x20));
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)next_token);
  return token;
}

