c1_token * __cdecl lex_scan_token_fragment(void)

{
  g_input_ptr = g_input_ptr + -1;
  return g_token_less;
}

