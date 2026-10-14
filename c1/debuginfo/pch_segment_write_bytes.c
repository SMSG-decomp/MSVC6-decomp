void __thiscall pch_segment_write_bytes(c1_pch_segment *segment,HANDLE file)

{
  HANDLE nNumberOfBytesToWrite;
  HANDLE hFile;
  
  hFile = file;
  _g_io_result = SetFilePointer(file,segment->file_offset,(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56);
  }
  nNumberOfBytesToWrite = (HANDLE)segment->size;
  WriteFile(hFile,segment->base,(DWORD)nNumberOfBytesToWrite,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != nNumberOfBytesToWrite) {
    diag_fatal_file_lasterror(0x55);
  }
  return;
}

