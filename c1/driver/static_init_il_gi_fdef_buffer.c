void static_init_il_gi_fdef_buffer(void)

{
  static_ctor_il_gi_fdef_buffer();
  c1_atexit(static_dtor_il_gi_fdef_buffer);
  return;
}

