void __cdecl ilstore_fatal_write_error(int key,int size)

{
  char *file;
  int iVar1;
  char acStack_104 [248];
  void *return_address;
  
  return_address = (void *)0x10644bee;
  iVar1 = (*g_ilmod->vtbl->get_kind_il)(g_ilmod,(uchar)key,(void *)size);
  if (iVar1 != 0) {
    return;
  }
  file = (*g_ilstore_pdb->vtbl->QueryPDBName)(g_ilstore_pdb,acStack_104);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

