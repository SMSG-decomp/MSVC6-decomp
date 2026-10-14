uint __cdecl file_current_at_eof(void)

{
  return CONCAT31((int3)((uint)g_input_file >> 8),g_input_file->flags) & 0xffffff01;
}

