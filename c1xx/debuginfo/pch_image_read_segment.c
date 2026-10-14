c1xx_pch_stream_reader * __cdecl pch_image_read_segment(void *file,c1xx_pch_image *image)

{
  char *pcVar1;
  c1_u8 *reader;
  void *hFile;
  c1xx_pch_image *owner;
  DWORD DVar2;
  c1xx_pch_stream_reader *pcVar3;
  DWORD local_4;
  
  hFile = file;
  DVar2 = SetFilePointer(file,0,(PLONG)0x0,1);
  owner = image;
  pcVar1 = image->file_name;
  ReadFile(hFile,&local_4,4,(LPDWORD)&image,(LPOVERLAPPED)0x0);
  if (image != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  if (DVar2 != local_4) {
    diag_fatal(0x354,owner->file_name);
  }
  pcVar1 = owner->file_name;
  file = (void *)0x0;
  ReadFile(hFile,&file,4,(LPDWORD)&image,(LPOVERLAPPED)0x0);
  if (image != (c1xx_pch_image *)0x4) {
    diag_fatal_file_lasterror(0x54,0x158,pcVar1);
  }
  reader = g_arenas[1].cur;
  if (file != (void *)0x3) {
    g_arenas[1].cur = g_arenas[1].cur + 0x4c;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    if (reader != (c1_u8 *)0x0) {
      pcVar3 = pch_stream_reader_new((c1xx_pch_stream_reader *)reader,hFile,(int)file,owner);
      pcVar3->header_offset = DVar2;
      return pcVar3;
    }
    DRam00000004 = DVar2;
    return (c1xx_pch_stream_reader *)0x0;
  }
  return (c1xx_pch_stream_reader *)0x0;
}

