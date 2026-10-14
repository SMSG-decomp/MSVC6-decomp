char * __cdecl lex_mark_paren_candidate(char *token)

{
  byte *next_token;
  c1_u8 *pcVar1;
  char *pcVar2;
  
  next_token = token_next((c1_token_reader *)&g_token_position);
  if ((g_compile_flags_c4 & 0x10000000) != 0) {
    if ((g_compile_flags_c4 & 8) == 0) {
      *token = -0x5c;
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)next_token);
      return token;
    }
    *token = '$';
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffff7;
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)next_token);
    return token;
  }
  if (((g_compile_flags_c4 & 0x40000000) != 0) && ((g_compile_flags_c4 & 0x8000000) != 0)) {
    pcVar2 = tree_new_from_token(next_token,token);
    return pcVar2;
  }
  lex_record_paren_run(token);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xbfffffff | 0x8000000;
  pcVar1 = parse_classify_candidate_token('\x01');
  return (char *)pcVar1;
}

