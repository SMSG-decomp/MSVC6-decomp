void __cdecl static_init_header_banner(void)

{
  static_ctor_header_banner();
  c1xx_atexit(import_ole_uninitialize);
  return;
}

