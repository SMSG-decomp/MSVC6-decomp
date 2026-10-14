void __cdecl pragma_skip_to_dash(c1_token *token)

{
  c1_u8 cVar1;
  
  cVar1 = token->code;
  while (cVar1 != '-') {
    token = token_next(&g_token_position);
    cVar1 = token->code;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
  return;
}

