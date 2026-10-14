int __cdecl c1xx_atexit(void *handler)

{
  if (g_atexit_count < 0x20) {
    *(void **)(&g_atexit_table + g_atexit_count * 4) = handler;
    g_atexit_count = g_atexit_count + 1;
    return 0;
  }
  diag_fatal(1,".\\main.c",0xa5c);
}

