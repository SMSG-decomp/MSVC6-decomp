void release_pdb_il_store(void)

{
  int iVar1;
  
  if (0 < g_pdb_il_module_count) {
    iVar1 = 0;
    if (0 < g_pdb_il_module_count) {
      do {
        ILModRelease(g_pdb_il_modules[iVar1]);
        iVar1 = iVar1 + 1;
      } while (iVar1 < g_pdb_il_module_count);
    }
    ILStoreRelease(g_pdb_il_store);
  }
  if (g_opt_incremental != 0) {
    StreamRelease(g_incr_info_stream);
    PDBCommit(g_pdb);
  }
  PDBClose(g_pdb);
  return;
}

