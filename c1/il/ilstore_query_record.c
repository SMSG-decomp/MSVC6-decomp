void __cdecl ilstore_query_record(int key,int kind,void *out)

{
  char *file;
  int iVar1;
  char acStack_104 [240];
  void *return_address;
  
  return_address = (void *)0x10644bd0;
  iVar1 = (*g_ilmod->vtbl->GetIL)(g_ilmod,key,(uchar)kind,out,(ulong *)&out);
  if (iVar1 != 0) {
    return;
  }
  file = (*g_ilstore_pdb->vtbl->QueryPDBName)(g_ilstore_pdb,acStack_104);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

