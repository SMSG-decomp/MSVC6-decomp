void __cdecl pragma_skip_to_dash(byte *token)

{
  byte bVar1;
  
  bVar1 = *token;
  while (bVar1 != 0x2d) {
    token = token_next((c1_token_reader *)&g_token_position);
    bVar1 = *token;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  return;
}

