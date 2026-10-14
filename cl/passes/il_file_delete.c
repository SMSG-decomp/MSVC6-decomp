void __cdecl il_file_delete(int suffix_index)

{
  size_t len;
  char path [1024];
  
  len = strlen(g_driver_ctx_ptr->temp_prefix);
  if (0x3ff < len + 10) {
    cl_error(0);
  }
  action_expand_percent(path,"%t",g_driver_ctx_ptr);
  strcat(path,g_il_temp_suffixes[suffix_index].suffix);
  _unlink(path);
  return;
}

