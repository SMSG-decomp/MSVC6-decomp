void __cdecl pragma_parse_list(void *each)

{
  c1_token *pcVar1;
  fe_name *pfVar2;
  c1_saved_token_stream *stream;
  c1_token_stream_vtbl *pcVar3;
  
  do {
    pcVar1 = token_next(&g_token_position);
    if (pcVar1->code == '\x06') {
      pfVar2 = (pcVar1->value).ptr;
    }
    else {
      stream = g_token_source->stream;
      pcVar3 = stream->vtbl;
      if (pcVar1->code != '\a') goto LAB_10622a2c;
      (*pcVar3->unget)(stream,pcVar1);
      pcVar1 = pragma_string_argument();
      pfVar2 = name_intern((pcVar1->value).string.text);
    }
    if (each != (void *)0x0) {
      (*each)(pfVar2);
    }
    pcVar1 = token_next(&g_token_position);
  } while (pcVar1->code == '7');
  stream = g_token_source->stream;
  pcVar3 = stream->vtbl;
LAB_10622a2c:
  (*pcVar3->unget)(stream,pcVar1);
  return;
}

