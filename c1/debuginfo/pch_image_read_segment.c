c1_pch_segment * __cdecl pch_image_read_segment(HANDLE file,c1_pch_image *image)

{
  uchar *reader;
  HANDLE hFile;
  c1_pch_image *owner;
  DWORD DVar1;
  c1_pch_segment *pcVar2;
  DWORD local_4;
  
  hFile = file;
  DVar1 = SetFilePointer(file,0,(PLONG)0x0,1);
  owner = image;
  ReadFile(hFile,&local_4,4,(LPDWORD)&image,(LPOVERLAPPED)0x0);
  if (image != (c1_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54);
  }
  if (DVar1 != local_4) {
    diag_fatal(0x354,owner->file_name);
  }
  file = (HANDLE)0x0;
  ReadFile(hFile,&file,4,(LPDWORD)&image,(LPOVERLAPPED)0x0);
  if (image != (c1_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54);
  }
  reader = g_arenas[1].cur;
  if (file != (HANDLE)0x3) {
    g_arenas[1].cur = g_arenas[1].cur + 0x4c;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    if (reader != (uchar *)0x0) {
      pcVar2 = pch_stream_reader_new((c1_pch_segment *)reader,hFile,(int)file,(uint)owner);
      pcVar2->header_offset = DVar1;
      return pcVar2;
    }
    DRam00000004 = DVar1;
    return (c1_pch_segment *)0x0;
  }
  return (c1_pch_segment *)0x0;
}

