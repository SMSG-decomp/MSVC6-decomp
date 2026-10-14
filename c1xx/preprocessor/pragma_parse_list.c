void __cdecl pragma_parse_list(void *each)

{
  byte *token;
  c1_u8 *pcVar1;
  void *pvVar2;
  c1xx_token_stream *token_stream;
  c1xx_token_stream_vtbl *pcVar3;
  
  do {
    token = token_next((c1_token_reader *)&g_token_position);
    if (*token == 6) {
      pvVar2 = *(void **)(token + 8);
    }
    else {
      token_stream = g_token_source->stream;
      pcVar3 = token_stream->vtbl;
      if (*token != 7) goto LAB_10455484;
      (*pcVar3->unget)(token_stream,(char *)token);
      pcVar1 = pragma_string_argument();
      pvVar2 = name_intern(*(char **)(pcVar1 + 8));
    }
    if (each != (void *)0x0) {
      (*each)(pvVar2);
    }
    token = token_next((c1_token_reader *)&g_token_position);
  } while (*token == 0x37);
  token_stream = g_token_source->stream;
  pcVar3 = token_stream->vtbl;
LAB_10455484:
  (*pcVar3->unget)(token_stream,(char *)token);
  return;
}

