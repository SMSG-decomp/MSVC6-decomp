void __cdecl pdb_state_construct_2(void)

{
  if (g_batch_continuing == '\0') {
    g_pdb_split.pdb = (PDB *)0x0;
    g_pdb_split.name_map = (NameMap *)0x0;
    g_pdb_split.tpi = (TPI *)0x0;
    g_pdb_split.stream_table = (fe_pdb_blob_table *)0x0;
    g_pdb_split.read_only = '\0';
    g_pdb_split.mre = (MREngine *)0x0;
  }
  return;
}

