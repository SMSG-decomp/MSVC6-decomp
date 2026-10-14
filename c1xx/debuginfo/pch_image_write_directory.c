void __fastcall pch_image_write_directory(c1xx_pch_image *image)

{
  char *pcVar1;
  DWORD DVar2;
  int iVar3;
  char local_5;
  DWORD local_4;
  
  _g_io_result = SetFilePointer(image->file,image->directory_offset,(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56,0x158,image->file_name);
  }
  pcVar1 = image->file_name;
  WriteFile(image->file,image,4,&local_4,(LPOVERLAPPED)0x0);
  if (local_4 != 4) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  local_5 = image->bitmap_segment != (c1xx_pch_stream_reader *)0x0;
  pcVar1 = image->file_name;
  WriteFile(image->file,&local_5,1,&local_4,(LPOVERLAPPED)0x0);
  if (local_4 != 1) {
    diag_fatal_file_lasterror(0x55,0x158,pcVar1);
  }
  if (local_5 == '\0') {
    file_skip_header_2(image->file,(int)image->file_name);
  }
  else {
    (*image->bitmap_segment->vtbl->pch_arena_segment_write_header)
              (image->bitmap_segment,image->file);
  }
  iVar3 = 0;
  if (0 < image->count) {
    do {
      (*image->segments[iVar3]->vtbl->pch_arena_segment_write_header)
                (image->segments[iVar3],image->file);
      iVar3 = iVar3 + 1;
    } while (iVar3 < image->count);
  }
  DVar2 = SetFilePointer(image->file,0,(PLONG)0x0,1);
  if (image->directory_end == 0) {
    pcVar1 = image->file_name;
    image->directory_end = DVar2;
    WriteFile(image->file,&image->directory_end,4,&local_4,(LPOVERLAPPED)0x0);
    if (local_4 != 4) {
      diag_fatal_file_lasterror(0x55,0x158,pcVar1);
      return;
    }
  }
  else if (DVar2 != image->directory_end) {
    diag_fatal(1,".\\nheapall.c",0xca2);
  }
  return;
}

