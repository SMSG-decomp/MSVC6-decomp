void __cdecl lex_skip_to_closing_brace(char before_open_brace)

{
  byte *token;
  int iVar1;
  
  iVar1 = -(uint)(before_open_brace != '\0');
  do {
    token = token_next((c1_token_reader *)&g_token_position);
    switch(*token) {
    case 0:
      return;
    case 0x6d:
      diag_fatal_simple(4);
    case 0x75:
      iVar1 = iVar1 + 1;
    default:
      g_string_literal_cur = &g_string_literal_buffer;
      break;
    case 0x7b:
      if (iVar1 == 0) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
        return;
      }
      iVar1 = iVar1 + -1;
      g_string_literal_cur = &g_string_literal_buffer;
    }
  } while( true );
}

