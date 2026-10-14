void __fastcall pch_heap_write_file(c1_pch_image *image)

{
  uchar *segment;
  c1_pch_segment *pcVar1;
  int iVar2;
  
  _g_io_result = CreateFileA(image->file_name,0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,
                             (HANDLE)0x0);
  image->file = _g_io_result;
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x53);
  }
  segment = g_arenas[1].cur;
  if ((image->relocation_arena != (fe_arena *)0x0) && (image->root == (c1_pch_segment *)0x0)) {
    g_arenas[1].cur = g_arenas[1].cur + 0x4c;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    if (segment == (uchar *)0x0) {
      pcVar1 = (c1_pch_segment *)0x0;
    }
    else {
      pcVar1 = pch_arena_segment_ctor((c1_pch_segment *)segment,image->relocation_arena,image);
    }
    image->root = pcVar1;
    _g_io_result = (HANDLE)SetFilePointer(image->file,0,(PLONG)0x0,2);
    if (_g_io_result == (HANDLE)0xffffffff) {
      diag_fatal_file_lasterror(0x56);
    }
    (*image->root->vtbl->pch_segment_append_to_file)(image->root,image->file);
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
  if (image->relocation_arena != (fe_arena *)0x0) {
    arena_release(image->relocation_arena);
    image->relocation_arena = (fe_arena *)0x0;
  }
  _g_io_result = (HANDLE)CloseHandle(image->file);
  if (_g_io_result == (HANDLE)0x0) {
    diag_fatal_file_lasterror(0x52);
  }
  image->file = (void *)0x0;
  return;
}

