void __thiscall pch_segment_read_bytes(c1xx_pch_stream_reader *pch_stream_reader,void *file)

{
  void *nNumberOfBytesToRead;
  char *file_00;
  void *hFile;
  
  if (g_abort_requested != 0) {
    c1xx_abort_if_running();
  }
  hFile = file;
  _g_io_result = SetFilePointer(file,pch_stream_reader->file_offset,(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56,0x158,pch_stream_reader->owner->file_name);
  }
  nNumberOfBytesToRead = (void *)pch_stream_reader->size;
  file_00 = pch_stream_reader->owner->file_name;
  ReadFile(hFile,pch_stream_reader->address,(DWORD)nNumberOfBytesToRead,(LPDWORD)&file,
           (LPOVERLAPPED)0x0);
  if (file != nNumberOfBytesToRead) {
    diag_fatal_file_lasterror(0x54,0x158,file_00);
  }
  if (g_abort_requested != 0) {
    c1xx_abort_if_running();
  }
  return;
}

