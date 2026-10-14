void __cdecl pdb_state_construct(void)

{
  if (g_batch_continuing == '\0') {
    g_pdb.pdb = (PDB *)0x0;
    g_pdb.name_map = (NameMap *)0x0;
    g_pdb.tpi = (TPI *)0x0;
    g_pdb.stream_table = (fe_pdb_blob_table *)0x0;
    g_pdb.read_only = '\0';
    g_pdb.mre = (MREngine *)0x0;
  }
  return;
}

