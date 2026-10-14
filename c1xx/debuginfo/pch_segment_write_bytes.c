void __thiscall pch_segment_write_bytes(void *pch_stream_reader,void *file)

{
  void *nNumberOfBytesToWrite;
  char *file_00;
  void *hFile;
  
  hFile = file;
  _g_io_result = SetFilePointer(file,*(LONG *)((int)pch_stream_reader + 0x14),(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56,0x158,*(char **)(*(int *)((int)pch_stream_reader + 0x10) + 0x10))
    ;
  }
  nNumberOfBytesToWrite = *(void **)((int)pch_stream_reader + 0x1c);
  file_00 = *(char **)(*(int *)((int)pch_stream_reader + 0x10) + 0x10);
  WriteFile(hFile,*(LPCVOID *)((int)pch_stream_reader + 0x18),(DWORD)nNumberOfBytesToWrite,
            (LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != nNumberOfBytesToWrite) {
    diag_fatal_file_lasterror(0x55,0x158,file_00);
  }
  return;
}

