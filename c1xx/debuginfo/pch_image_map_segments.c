byte __fastcall pch_image_map_segments(c1xx_pch_image *image)

{
  c1xx_pch_stream_reader *pch_stream_reader;
  bool bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  time_t tVar5;
  byte bVar6;
  int unused;
  
  bVar6 = 0;
  unused = 0;
  if ((g_pch_image_map_guard & 1) == 0) {
    g_pch_image_map_guard = g_pch_image_map_guard | 1;
    g_os_is_windows_nt = os_is_windows_nt();
  }
  if (g_os_is_windows_nt != 0) {
    bVar1 = false;
    pvVar2 = pch_image_create_mapping(image,8,(uint *)0x0);
    image->mapping = pvVar2;
    if (pvVar2 != (void *)0x0) {
      iVar4 = 0;
      while (iVar4 < image->count) {
        iVar3 = (*image->segments[iVar4]->vtbl->pch_segment_map_view)
                          (image->segments[iVar4],image->mapping,'\0',(void *)0x0);
        if (iVar3 != 6) {
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
        if (bVar1) {
          bVar6 = pch_image_map_blocks(iVar4,&image->count,0,bVar6,unused);
          return bVar6;
        }
      }
      if (!bVar1) {
        return 0;
      }
      for (iVar4 = iVar4 + -2; -1 < iVar4; iVar4 = iVar4 + -1) {
        (*image->segments[iVar4]->vtbl->pch_segment_release)(image->segments[iVar4]);
      }
      pvVar2 = image->mapping;
      image->mapping = (void *)0x0;
      image->mapping_to_close = pvVar2;
    }
  }
  bVar1 = false;
  iVar4 = 0;
  if (0 < image->count) {
    do {
      iVar3 = (*image->segments[iVar4]->vtbl->pch_segment_alloc_at_base)
                        (image->segments[iVar4],image->file);
      if (iVar3 != 6) {
        bVar1 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < image->count);
    if (bVar1) {
      if (g_opt_BMOVE != '\0') {
        tVar5 = time((time_t *)0x0);
        srand((uint)tVar5);
      }
      iVar4 = 0;
      if (0 < image->count) {
        do {
          pch_stream_reader = image->segments[iVar4];
          if ((pch_stream_reader->state != 6) &&
             (iVar3 = (*pch_stream_reader->vtbl->pch_segment_alloc_anywhere)
                                (pch_stream_reader,image->file,0), iVar3 == 5)) {
            unused = unused + 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < image->count);
        if (unused != 0) {
          pch_image_relocate(image,unused);
          bVar6 = 1;
        }
      }
    }
  }
  if (image->mapping_to_close != (HANDLE)0x0) {
    _g_io_result = CloseHandle(image->mapping_to_close);
    if (_g_io_result == 0) {
      diag_fatal_file_lasterror(0x52,0x158,image->file_name);
    }
    image->mapping_to_close = (void *)0x0;
  }
  if (image->file != (HANDLE)0x0) {
    _g_io_result = CloseHandle(image->file);
    if (_g_io_result == 0) {
      diag_fatal_file_lasterror(0x52,0x158,image->file_name);
    }
    image->file = (void *)0x0;
  }
  return bVar6;
}

