void __thiscall pch_arena_segment_write_header(c1xx_pch_stream_reader *obj,HANDLE file)

{
  char *pcVar1;
  HANDLE hFile;
  
  hFile = file;
  pch_segment_write_base_header((c1xx_nheap_object_base *)obj,file);
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->file_offset,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->base,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->size,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->saved_bitmap,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  pcVar1 = obj->owner->file_name;
  WriteFile(hFile,&obj->desc_word,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  return;
}

