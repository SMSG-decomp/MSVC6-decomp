void dynamic_init_msvcrt_handle(void)

{
  msvcrt_handle_init();
  c1_atexit(msvcrt_handle_destroy);
  return;
}

