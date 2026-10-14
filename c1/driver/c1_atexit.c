int __cdecl c1_atexit(void *handler)

{
  if (g_atexit_count < 0x20) {
    g_atexit_table[g_atexit_count] = handler;
    g_atexit_count = g_atexit_count + 1;
    return 0;
  }
  diag_fatal(1,".\\main.c",0xa5c);
}

