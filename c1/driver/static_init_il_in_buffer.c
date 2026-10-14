void static_init_il_in_buffer(void)

{
  static_ctor_il_in_buffer();
  c1_atexit(static_dtor_il_in_buffer);
  return;
}

