void __cdecl ilstore_open(c1xx_pdb *pdb)

{
  int iVar1;
  char *file;
  char pdb_name [244];
  uint open_ret_slot;
  
  g_ilstore_pdb = pdb;
  iVar1 = ILStore::open((PDB *)pdb,1,(ILStore **)&g_ilstore);
  if (iVar1 != 0) {
    iVar1 = (*g_ilstore->vtbl->query_version)(g_ilstore,"EEA",(uchar *)&pdb);
    if ((iVar1 != 0) && ((char)pdb == '\x05')) {
      return;
    }
  }
  file = (char *)(*g_ilstore_pdb->vtbl->query_pdb_name)(pdb_name);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

