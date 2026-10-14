void __cdecl static_init_pdb_state(void)

{
  static_ctor_pdb_state();
  c1xx_atexit(static_dtor_pdb_state);
  return;
}

