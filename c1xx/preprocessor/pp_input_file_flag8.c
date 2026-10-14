uint __cdecl pp_input_file_flag8(void)

{
  return CONCAT31((int3)((uint)g_input_file >> 8),g_input_file->flags >> 3) & 0xffffff01;
}

