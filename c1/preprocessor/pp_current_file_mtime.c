int __cdecl pp_current_file_mtime(void)

{
  int local_4;
  
  file_mtime_of_handle(g_source_handle,&local_4);
  return local_4;
}

