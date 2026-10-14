void __cdecl static_init_msvcrt_handle(void)

{
  static_ctor_msvcrt_handle();
  c1xx_atexit(msvcrt_handle_destroy);
  return;
}

