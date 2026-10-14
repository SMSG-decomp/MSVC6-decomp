char __cdecl lex_at_buffer_start(void)

{
  return g_input_ptr == g_input_file->buffer;
}

