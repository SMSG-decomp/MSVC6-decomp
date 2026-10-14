void __cdecl static_init_il_db_buffer(void)

{
  static_ctor_il_db_buffer();
  c1xx_atexit(static_dtor_il_db_buffer);
  return;
}

