void __cdecl file_skip_header(HANDLE h,char *file_name)

{
  _g_io_result = SetFilePointer(h,0x1c,(PLONG)0x0,1);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56);
  }
  return;
}

