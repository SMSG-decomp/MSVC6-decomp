void __thiscall pch_segment_write_base_header(c1_pch_segment *obj,HANDLE file)

{
  HANDLE hFile;
  DWORD DVar1;
  
  hFile = file;
  DVar1 = SetFilePointer(file,0,(PLONG)0x0,1);
  if (obj->header_offset == 0) {
    obj->header_offset = DVar1;
  }
  else if (DVar1 != obj->header_offset) {
    diag_fatal(1,".\\nheapall.c",0x5c9);
  }
  WriteFile(hFile,&obj->header_offset,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  WriteFile(hFile,&obj->kind,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  return;
}

