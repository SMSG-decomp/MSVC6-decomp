void __cdecl pp_warn_extra_tokens(char *directive)

{
  byte c;
  
  do {
    c = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
  } while (g_char_class[c] == '\x01');
  if ((g_char_flags[c] & 0x20) == 0) {
    c = lex_skip_comment(c);
  }
  if (c != 10) {
    if ((g_ms_extensions == '\0') || ((directive != "#else" && (directive != "#endif")))) {
      diag_warning(1,0x43,directive);
    }
    lex_skip_whitespace();
    return;
  }
  g_input_ptr = g_input_ptr + -1;
  return;
}

