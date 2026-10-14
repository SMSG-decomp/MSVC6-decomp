void static_init_il_pending_init_buffer(void)

{
  static_ctor_il_pending_init_buffer();
  c1_atexit(static_dtor_il_pending_init_buffer);
  return;
}

