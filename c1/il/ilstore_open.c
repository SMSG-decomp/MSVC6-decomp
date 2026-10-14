void __cdecl ilstore_open(void *pdb)

{
  int iVar1;
  char *file;
  char acStack_104 [244];
  void *return_address;
  
  g_ilstore_pdb = pdb;
  return_address = (void *)0x106447c5;
  iVar1 = ILStore::open(pdb,1,(ILStore **)&g_ilstore);
  if (iVar1 != 0) {
    iVar1 = (*g_ilstore->vtbl->GetILSType)(g_ilstore,"EEA",(uchar *)&pdb);
    if ((iVar1 != 0) && ((char)pdb == '\x05')) {
      return;
    }
  }
  file = (*g_ilstore_pdb->vtbl->QueryPDBName)(g_ilstore_pdb,acStack_104);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

