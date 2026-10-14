void __thiscall pch_arena_segment_write_header(c1_pch_segment *segment,HANDLE file)

{
  HANDLE hFile;
  
  hFile = file;
  pch_segment_write_base_header(segment,file);
  WriteFile(hFile,&segment->file_offset,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  WriteFile(hFile,&segment->base,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  WriteFile(hFile,&segment->size,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  WriteFile(hFile,&segment->saved_bitmap,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  WriteFile(hFile,&segment->descriptor_word,4,(LPDWORD)&file,(LPOVERLAPPED)0x0);
  if (file != (HANDLE)0x4) {
    diag_fatal_file_lasterror(0x55);
  }
  return;
}

