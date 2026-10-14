void __thiscall pch_image_index_read(c1_pch_image *index,LPCSTR file_name,DWORD offset)

{
  uchar *puVar1;
  c1_pch_segment *pcVar2;
  DWORD DVar3;
  int iVar4;
  
  index->file_name = file_name;
  index->directory_offset = offset;
  _g_io_result = CreateFileA(file_name,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,
                             (HANDLE)0x0);
  index->file = _g_io_result;
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x53);
  }
  _g_io_result = (HANDLE)SetFilePointer(index->file,index->directory_offset,(PLONG)0x0,0);
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x56);
  }
  ReadFile(index->file,index,4,&offset,(LPOVERLAPPED)0x0);
  if (offset != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  file_name = (LPCSTR)((uint)file_name & 0xffffff00);
  ReadFile(index->file,&file_name,1,&offset,(LPOVERLAPPED)0x0);
  if (offset != 1) {
    diag_fatal_file_lasterror(0x54);
  }
  if ((char)file_name == '\0') {
    index->root = (c1_pch_segment *)0x0;
    file_skip_header(index->file,index->file_name);
  }
  else {
    pcVar2 = pch_image_read_segment(index->file,index);
    index->root = pcVar2;
  }
  puVar1 = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + index->count * 4;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  index->segments = (c1_pch_segment **)puVar1;
  iVar4 = 0;
  index->next_index = index->count;
  if (0 < index->count) {
    do {
      pcVar2 = pch_image_read_segment(index->file,index);
      index->segments[iVar4] = pcVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < index->count);
  }
  DVar3 = SetFilePointer(index->file,0,(PLONG)0x0,1);
  ReadFile(index->file,&index->end_offset,4,&offset,(LPOVERLAPPED)0x0);
  if (offset != 4) {
    diag_fatal_file_lasterror(0x54);
  }
  if (index->end_offset != DVar3) {
    diag_fatal(0x354,index->file_name);
  }
  return;
}

