char __cdecl lex_begin_primary_file(void)

{
  char cVar1;
  
  g_input_ptr = g_input_ptr + -1;
  g_lex_position = g_lex_position + -1;
  g_token_position = g_lex_position;
  if ((g_opt_E_preprocess == 0) && (g_eh_declarations_injected == 0)) {
    lex_push_builtin_prelude();
    g_eh_declarations_injected = 1;
    return '\x01';
  }
  cVar1 = lex_push_next_forced_include();
  if (cVar1 == '\0') {
    g_lex_position = g_lex_position + 1;
    g_token_position = g_lex_position;
    g_input_ptr = g_input_ptr + 1;
    return '\0';
  }
  return '\x01';
}

