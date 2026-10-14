void __fastcall pch_image_close(c1_pch_image *image)

{
  c1_pch_segment *segment;
  int iVar1;
  
  if (image->segments != (c1_pch_segment **)0x0) {
    iVar1 = 0;
    if (0 < image->count) {
      do {
        segment = image->segments[iVar1];
        if ((segment != (c1_pch_segment *)0x0) && (segment->state == 6)) {
          (*segment->vtbl->pch_segment_release)(segment);
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < image->count);
    }
    if (image->mapping != (HANDLE)0x0) {
      CloseHandle(image->mapping);
      image->mapping = (void *)0x0;
    }
    if (image->mapping_kept != (HANDLE)0x0) {
      CloseHandle(image->mapping_kept);
      image->mapping_kept = (void *)0x0;
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

