void __thiscall pch_segment_write_base_header(c1xx_nheap_object_base *obj,HANDLE file)

{
  char *pcVar1;
  HANDLE hFile;
  DWORD DVar2;
  
  hFile = file;
  DVar2 = SetFilePointer(file,0,(PLONG)0x0,1);
  if (obj->header_offset == 0) {
    obj->header_offset = DVar2;
  }
  else if (DVar2 != obj->header_offset) {
    diag_fatal(1,".\\nheapall.c",0x5c9);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->header_offset,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->kind,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  return;
}

