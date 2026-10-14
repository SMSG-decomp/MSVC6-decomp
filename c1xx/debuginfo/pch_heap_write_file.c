void __fastcall pch_heap_write_file(c1xx_pch_image *image)

{
  c1_u8 *segment;
  c1xx_pch_stream_reader *pcVar1;
  int iVar2;
  
  _g_io_result = CreateFileA(image->file_name,0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,
                             (HANDLE)0x0);
  image->file = _g_io_result;
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x53,0x158,image->file_name);
  }
  segment = g_arenas[1].cur;
  if ((image->arena != (c1_arena *)0x0) && (image->bitmap_segment == (c1xx_pch_stream_reader *)0x0))
  {
    g_arenas[1].cur = g_arenas[1].cur + 0x4c;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    if (segment == (c1_u8 *)0x0) {
      pcVar1 = (c1xx_pch_stream_reader *)0x0;
    }
    else {
      pcVar1 = pch_arena_segment_ctor((c1xx_pch_stream_reader *)segment,image->arena,image);
    }
    image->bitmap_segment = pcVar1;
    _g_io_result = (HANDLE)SetFilePointer(image->file,0,(PLONG)0x0,2);
    if (_g_io_result == (HANDLE)0xffffffff) {
      diag_fatal_file_lasterror(0x56,0x158,image->file_name);
    }
    (*image->bitmap_segment->vtbl->pch_segment_append_to_file)(image->bitmap_segment,image->file);
  }
  iVar2 = 0;
  if (0 < image->count) {
    do {
      (*image->segments[iVar2]->vtbl->pch_segment_write_contents)
                (image->segments[iVar2],(uint)image->file);
      iVar2 = iVar2 + 1;
    } while (iVar2 < image->count);
  }
  pch_image_write_directory(image);
  if (image->arena != (c1_arena *)0x0) {
    arena_release(image->arena);
    image->arena = (c1_arena *)0x0;
  }
  _g_io_result = (HANDLE)CloseHandle(image->file);
  if (_g_io_result == (HANDLE)0x0) {
    diag_fatal_file_lasterror(0x52,0x158,image->file_name);
  }
  image->file = (void *)0x0;
  return;
}

