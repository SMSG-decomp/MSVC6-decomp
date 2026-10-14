bool lex_input_at_end(void)

{
  return g_input_ptr == g_input_file->buffer;
}

