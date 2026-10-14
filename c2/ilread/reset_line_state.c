uint32_t reset_line_state(void)

{
  g_line_run_closed = 1;
  g_line_run_cursor = (c2_line_run *)0x0;
  g_reader_source_file = (char *)0x0;
  return g_line_high_water;
}

