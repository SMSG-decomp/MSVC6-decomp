c1_u8 __cdecl file_current_at_eof(void)

{
  return g_input_file->flags & 1;
}

