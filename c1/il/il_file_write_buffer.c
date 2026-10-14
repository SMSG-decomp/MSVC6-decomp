size_t __cdecl il_file_write_buffer(size_t buf)

{
  void *_Str;
  
  _Str = (void *)il_buffer_put_pch_reference((fe_il_buffer *)buf,(int *)&buf);
  _g_io_result = fwrite(_Str,1,buf,g_pch_file);
  if (_g_io_result != buf) {
    diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    return buf;
  }
  return buf;
}

