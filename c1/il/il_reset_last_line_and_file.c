void __cdecl il_reset_last_line_and_file(void)

{
  g_il_line_base = 0xffffffff;
  g_il_last_file_key = 0xffffffff;
  return;
}

