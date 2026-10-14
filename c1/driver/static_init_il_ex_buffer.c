void static_init_il_ex_buffer(void)

{
  static_ctor_il_ex_buffer();
  c1_atexit(static_dtor_il_ex_buffer);
  return;
}

