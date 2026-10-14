void dynamic_init_g_pdb(void)

{
  pdb_state_construct();
  c1_atexit(pdb_state_destroy);
  return;
}

