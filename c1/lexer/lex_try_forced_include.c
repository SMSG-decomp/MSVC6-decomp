char __cdecl lex_try_forced_include(void)

{
  char cVar1;
  
  g_input_ptr = g_input_ptr + -1;
  g_lex_position = g_lex_position + -1;
  g_token_position = g_lex_position;
  cVar1 = lex_push_next_forced_include();
  if (cVar1 == '\0') {
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    g_input_ptr = g_input_ptr + 1;
    return '\0';
  }
  return '\x01';
}

