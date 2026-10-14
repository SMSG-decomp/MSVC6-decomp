void __cdecl include_close_all(void)

{
  if (g_input_file != (fe_input_file *)0x0) {
    do {
      if (-1 < g_input_file->handle) {
        _close(g_input_file->handle);
      }
      g_input_file = g_input_file->next;
    } while (g_input_file != (fe_input_file *)0x0);
    g_input_file = (fe_input_file *)0x0;
  }
  return;
}

