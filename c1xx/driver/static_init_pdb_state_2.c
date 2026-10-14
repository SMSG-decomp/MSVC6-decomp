void __cdecl static_init_pdb_state_2(void)

{
  static_ctor_pdb_state_2();
  c1xx_atexit(static_dtor_pdb_state_2);
  return;
}

