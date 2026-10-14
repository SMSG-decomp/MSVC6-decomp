void __cdecl ilstore_report_error(void)

{
  char *file;
  char name_buf [260];
  
  file = (char *)(*g_ilstore_pdb->vtbl->query_pdb_name)(name_buf);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

