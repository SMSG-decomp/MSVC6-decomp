void __cdecl static_ctor_pdb_state_2(void)

{
  if (g_batch_continuing == '\0') {
    g_pdb_split.pdb = (c1xx_pdb *)0x0;
    g_pdb_split.namemap = (c1_pdb_namemap *)0x0;
    g_pdb_split.tpi = (c1_pdb_tpi *)0x0;
    g_pdb_split.blob_table = (c1_pdb_blob_table *)0x0;
    g_pdb_split.read_only = '\0';
    g_pdb_split.mre = (c1_mre_engine *)0x0;
  }
  return;
}

