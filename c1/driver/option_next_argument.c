char * __cdecl option_next_argument(void)

{
  g_option_args_left = g_option_args_left + -1;
  if (0 < g_option_args_left) {
    g_option_argv_cursor = g_option_argv_cursor + 1;
    return *g_option_argv_cursor;
  }
  return (char *)0x0;
}

