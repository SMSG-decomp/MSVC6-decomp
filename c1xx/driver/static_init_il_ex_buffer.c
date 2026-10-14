void __cdecl static_init_il_ex_buffer(void)

{
  static_ctor_il_ex_buffer();
  c1xx_atexit(static_dtor_il_ex_buffer);
  return;
}

