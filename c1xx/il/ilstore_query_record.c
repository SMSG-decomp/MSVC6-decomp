void __cdecl ilstore_query_record(int key,int space,void **data)

{
  char *file;
  int iVar1;
  char name_buf [256];
  
  iVar1 = (*g_ilmod->vtbl->get_record)();
  if (iVar1 != 0) {
    return;
  }
  file = (char *)(*g_ilstore_pdb->vtbl->query_pdb_name)(name_buf);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

