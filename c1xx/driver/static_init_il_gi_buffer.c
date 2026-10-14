void __cdecl static_init_il_gi_buffer(void)

{
  static_ctor_il_gi_buffer();
  c1xx_atexit(static_dtor_il_gi_buffer);
  return;
}

