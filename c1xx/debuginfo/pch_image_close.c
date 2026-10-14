void __fastcall pch_image_close(c1xx_pch_image *image)

{
  c1xx_pch_stream_reader *pch_stream_reader;
  int iVar1;
  
  if (image->segments != (c1xx_pch_stream_reader **)0x0) {
    iVar1 = 0;
    if (0 < image->count) {
      do {
        pch_stream_reader = image->segments[iVar1];
        if ((pch_stream_reader != (c1xx_pch_stream_reader *)0x0) && (pch_stream_reader->state == 6))
        {
          (*pch_stream_reader->vtbl->pch_segment_release)(pch_stream_reader);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < image->count);
    }
    if (image->mapping != (HANDLE)0x0) {
      CloseHandle(image->mapping);
      image->mapping = (void *)0x0;
    }
    if (image->mapping_to_close != (HANDLE)0x0) {
      CloseHandle(image->mapping_to_close);
      image->mapping_to_close = (void *)0x0;
    }
    if (image->handle28 != (HANDLE)0x0) {
      CloseHandle(image->handle28);
      image->handle28 = (void *)0x0;
    }
    if (image->handle30 != (HANDLE)0x0) {
      CloseHandle(image->handle30);
      image->handle30 = (void *)0x0;
    }
    if (image->handle24 != (HANDLE)0x0) {
      CloseHandle(image->handle24);
      image->handle24 = (void *)0x0;
    }
    if (image->handle2c != (HANDLE)0x0) {
      CloseHandle(image->handle2c);
      image->handle2c = (void *)0x0;
    }
    if (image->file != (HANDLE)0x0) {
      CloseHandle(image->file);
      image->file = (void *)0x0;
    }
  }
  return;
}

