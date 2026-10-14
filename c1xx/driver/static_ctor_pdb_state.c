void __cdecl static_ctor_pdb_state(void)

{
  if (g_batch_continuing == '\0') {
    g_pdb.pdb = (c1xx_pdb *)0x0;
    g_pdb.namemap = (c1_pdb_namemap *)0x0;
    g_pdb.tpi = (c1_pdb_tpi *)0x0;
    g_pdb.blob_table = (c1_pdb_blob_table *)0x0;
    g_pdb.read_only = '\0';
    g_pdb.mre = (c1_mre_engine *)0x0;
  }
  return;
}

