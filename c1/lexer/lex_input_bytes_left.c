int lex_input_bytes_left(void)

{
  void *pvVar1;
  
  pvVar1 = lex_source_input_ptr();
  return (int)(g_input_file->buffer + (g_input_file->last_read - (int)pvVar1));
}

