void __cdecl ilstore_report_error(void)

{
  char *file;
  char file_name [260];
  
  file = (*g_ilstore_pdb->vtbl->QueryPDBName)(g_ilstore_pdb,file_name);
  diag_fatal_file_errno(0x28,0x162,file);
  return;
}

