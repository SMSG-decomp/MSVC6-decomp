void lex_reset_buffers(void)

{
  g_lex_unread_word = 0;
  g_macro_arg_cursor = g_macro_arg_buffer;
  g_macro_text_cursor = g_macro_text_buffer;
  g_macro_expansion_text_start = g_macro_text_buffer;
  return;
}

