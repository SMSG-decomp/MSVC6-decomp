void __fastcall pch_image_write_directory(c1_pch_image *image)

{
  DWORD DVar1;
  int iVar2;
  char local_5;
  DWORD local_4;
  
  _g_io_result = SetFilePointer(image->file,image->directory_offset,(PLONG)0x0,0);
  if (_g_io_result == 0xffffffff) {
    diag_fatal_file_lasterror(0x56);
  }
  WriteFile(image->file,image,4,&local_4,(LPOVERLAPPED)0x0);
  if (local_4 != 4) {
    diag_fatal_file_lasterror(0x55);
  }
  local_5 = image->root != (c1_pch_segment *)0x0;
  WriteFile(image->file,&local_5,1,&local_4,(LPOVERLAPPED)0x0);
  if (local_4 != 1) {
    diag_fatal_file_lasterror(0x55);
  }
  if (local_5 == '\0') {
    file_skip_header_2(image->file,image->file_name);
  }
  else {
    (*image->root->vtbl->pch_arena_segment_write_header)(image->root,image->file);
  }
  iVar2 = 0;
  if (0 < image->count) {
    do {
      (*image->segments[iVar2]->vtbl->pch_arena_segment_write_header)
                (image->segments[iVar2],image->file);
      iVar2 = iVar2 + 1;
    } while (iVar2 < image->count);
  }
  DVar1 = SetFilePointer(image->file,0,(PLONG)0x0,1);
  if (image->end_offset == 0) {
    image->end_offset = DVar1;
    WriteFile(image->file,&image->end_offset,4,&local_4,(LPOVERLAPPED)0x0);
    if (local_4 != 4) {
      diag_fatal_file_lasterror(0x55);
      return;
    }
  }
  else if (DVar1 != image->end_offset) {
    diag_fatal(1,".\\nheapall.c",0xca2);
  }
  return;
}

