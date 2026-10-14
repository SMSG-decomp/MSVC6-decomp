char ** argv_snapshot_remaining(void)

{
  char *pcVar1;
  char **ppcVar2;
  
  ppcVar2 = g_option_argv_buffer;
  g_option_argv_buffer[0] = *g_option_argv_cursor;
  pcVar1 = g_option_argv_buffer[0];
  while (pcVar1 != (char *)0x0) {
    g_option_argv_cursor = g_option_argv_cursor + 1;
    pcVar1 = *g_option_argv_cursor;
    ppcVar2 = ppcVar2 + 1;
    *ppcVar2 = pcVar1;
  }
  g_option_argv_cursor = g_option_argv_buffer;
  return ppcVar2;
}

