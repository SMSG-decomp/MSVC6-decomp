void __cdecl static_init_il_gl_buffer(void)

{
  static_ctor_il_gl_buffer();
  c1xx_atexit(static_dtor_il_gl_buffer);
  return;
}

