void __thiscall pch_segment_read_bytes(c1_pch_segment *segment,HANDLE file)

{
  HANDLE nNumberOfBytesToRead;
  HANDLE hFile;
  
  if (g_abort_requested != 0) {
    c1_abort_if_running();
  }
  hFile = file;
  _g_io_result = SetFilePointer(file,segment->file_offset,(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56);
  }
  nNumberOfBytesToRead = (HANDLE)segment->size;
  ReadFile(hFile,segment->address,(DWORD)nNumberOfBytesToRead,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != nNumberOfBytesToRead) {
    diag_fatal_file_lasterror(0x54);
  }
  if (g_abort_requested != 0) {
    c1_abort_if_running();
  }
  return;
}

