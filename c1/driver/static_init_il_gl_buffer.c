void static_init_il_gl_buffer(void)

{
  static_ctor_il_gl_buffer();
  c1_atexit(static_dtor_il_gl_buffer);
  return;
}

