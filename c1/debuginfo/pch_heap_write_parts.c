void __thiscall pch_heap_write_parts(c1_pch_image *image,char *name,int offset)

{
  int iVar1;
  
  image->file_name = name;
  image->directory_offset = offset;
  _g_io_result = CreateFileA(name,0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000000,(HANDLE)0x0);
  image->file = _g_io_result;
  if (_g_io_result == (HANDLE)0xffffffff) {
    diag_fatal_file_lasterror(0x53);
  }
  pch_image_write_directory(image);
  iVar1 = 0;
  if (0 < image->count) {
    do {
      (*image->segments[iVar1]->vtbl->pch_segment_append_to_file)
                (image->segments[iVar1],image->file);
      iVar1 = iVar1 + 1;
    } while (iVar1 < image->count);
  }
  pch_image_write_directory(image);
  CloseHandle(image->file);
  image->file = (void *)0x0;
  return;
}

