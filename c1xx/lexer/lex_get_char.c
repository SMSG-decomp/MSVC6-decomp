byte __cdecl lex_get_char(void)

{
  byte c;
  
  c = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  if (g_char_class[c] == '\0') {
    c = lex_next_significant_char(c);
  }
  return c;
}

