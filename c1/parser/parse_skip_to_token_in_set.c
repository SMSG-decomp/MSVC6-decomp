c1_token * __cdecl parse_skip_to_token_in_set(c1_token *token,...)

{
  c1_u8 *pcVar1;
  int iVar2;
  int iVar3;
  va_list arg;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    if ((iVar3 == 0) && (iVar2 == 0)) {
      arg = (va_list)register0x00000010;
      do {
        pcVar1 = (c1_u8 *)(arg + 8);
        if (*pcVar1 == token->code) {
          return token;
        }
        arg = arg + 4;
      } while (*pcVar1 != '\x01');
    }
    switch(token->code) {
    case '\0':
      return g_token_newline;
    case 'm':
      diag_fatal_simple(4);
    case 'u':
      iVar3 = iVar3 + 1;
      token = token_next(&g_token_position);
      break;
    case 'v':
      iVar2 = iVar2 + 1;
      token = token_next(&g_token_position);
      break;
    case '{':
      iVar3 = iVar3 + -1;
      token = token_next(&g_token_position);
      break;
    case '~':
      iVar2 = iVar2 + -1;
      token = token_next(&g_token_position);
      break;
    case '\x7f':
      arena_reset_ptr(g_arenas + 3);
    case '\a':
      g_string_literal_cur = &g_string_literal_buffer;
    default:
      token = token_next(&g_token_position);
    }
  } while( true );
}

