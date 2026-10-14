void __cdecl static_init_il_sy_buffer(void)

{
  static_ctor_il_sy_buffer();
  c1xx_atexit(static_dtor_il_sy_buffer);
  return;
}

