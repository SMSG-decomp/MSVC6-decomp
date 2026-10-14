void __thiscall pch_image_index_read(c1xx_pch_image *image,char *file_name,uint offset)

{
  char *pcVar1;
  c1_u8 *pcVar2;
  c1xx_pch_stream_reader *pcVar3;
  DWORD DVar4;
  int iVar5;
  
  image->file_name = file_name;
  image->directory_offset = offset;
  _g_io_result = CreateFileA(file_name,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,
                             (HANDLE)0x0);
  image->file = _g_io_result;
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x53,0x158,image->file_name);
  }
  _g_io_result = (HANDLE)SetFilePointer(image->file,image->directory_offset,(PLONG)0x0,0);
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x56,0x158,image->file_name);
  }
  pcVar1 = image->file_name;
  ReadFile(image->file,image,4,&offset,(LPOVERLAPPED)0x0);
  if (offset != 4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  pcVar1 = image->file_name;
  file_name = (char *)((uint)file_name & 0xffffff00);
  ReadFile(image->file,&file_name,1,&offset,(LPOVERLAPPED)0x0);
  if (offset != 1) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  if ((char)file_name == '\0') {
    image->bitmap_segment = (c1xx_pch_stream_reader *)0x0;
    file_skip_header(image->file,image->file_name);
  }
  else {
    pcVar3 = pch_image_read_segment(image->file,image);
    image->bitmap_segment = pcVar3;
  }
  pcVar2 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + image->count * 4;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  image->segments = (c1xx_pch_stream_reader **)pcVar2;
  iVar5 = 0;
  image->next_index = image->count;
  if (0 < image->count) {
    do {
      pcVar3 = pch_image_read_segment(image->file,image);
      image->segments[iVar5] = pcVar3;
      iVar5 = iVar5 + 1;
    } while (iVar5 < image->count);
  }
  DVar4 = SetFilePointer(image->file,0,(PLONG)0x0,1);
  pcVar1 = image->file_name;
  ReadFile(image->file,&image->directory_end,4,&offset,(LPOVERLAPPED)0x0);
  if (offset != 4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  if (image->directory_end == DVar4) {
    return;
  }
  diag_fatal(0x354,image->file_name);
}

