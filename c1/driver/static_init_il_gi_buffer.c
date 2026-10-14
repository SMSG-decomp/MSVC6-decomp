void static_init_il_gi_buffer(void)

{
  static_ctor_il_gi_buffer();
  c1_atexit(static_dtor_il_gi_buffer);
  return;
}

