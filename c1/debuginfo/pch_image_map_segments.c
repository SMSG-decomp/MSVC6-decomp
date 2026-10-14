byte __fastcall pch_image_map_segments(c1_pch_image *index)

{
  c1_pch_segment *segment;
  bool bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  time_t tVar5;
  byte local_5;
  int local_4;
  
  local_5 = 0;
  local_4 = 0;
  if ((g_pch_image_map_guard & 1) == 0) {
    g_pch_image_map_guard = g_pch_image_map_guard | 1;
    g_os_is_windows_nt = os_is_windows_nt();
  }
  if (g_os_is_windows_nt != 0) {
    bVar1 = false;
    pvVar2 = pch_image_create_mapping(index,8,(uint *)0x0);
    index->mapping = pvVar2;
    if (pvVar2 != (void *)0x0) {
      iVar4 = 0;
      do {
        if (index->count <= iVar4) {
          if (!bVar1) {
            return 0;
          }
          break;
        }
        iVar3 = (*index->segments[iVar4]->vtbl->pch_segment_map_view)
                          (index->segments[iVar4],index->mapping,'\0',(void *)0x0);
        if (iVar3 != 6) {
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
      } while (!bVar1);
      for (iVar4 = iVar4 + -2; -1 < iVar4; iVar4 = iVar4 + -1) {
        (*index->segments[iVar4]->vtbl->pch_segment_release)(index->segments[iVar4]);
      }
      pvVar2 = index->mapping;
      index->mapping = (void *)0x0;
      index->mapping_kept = pvVar2;
    }
  }
  bVar1 = false;
  iVar4 = 0;
  if (0 < index->count) {
    do {
      iVar3 = (*index->segments[iVar4]->vtbl->pch_segment_alloc_at_base)
                        (index->segments[iVar4],index->file);
      if (iVar3 != 6) {
        bVar1 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < index->count);
    if (bVar1) {
      if (g_opt_BMOVE != '\0') {
        tVar5 = time((time_t *)0x0);
        srand((uint)tVar5);
      }
      iVar4 = 0;
      if (0 < index->count) {
        do {
          segment = index->segments[iVar4];
          if ((segment->state != 6) &&
             (iVar3 = (*segment->vtbl->pch_segment_alloc_anywhere)(segment,index->file,0),
             iVar3 == 5)) {
            local_4 = local_4 + 1;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < index->count);
        if (local_4 != 0) {
          pch_image_relocate(index,local_4);
          local_5 = 1;
        }
      }
    }
  }
  if (index->mapping_kept != (HANDLE)0x0) {
    _g_io_result = CloseHandle(index->mapping_kept);
    if (_g_io_result == 0) {
      diag_fatal_file_lasterror(0x52);
    }
    index->mapping_kept = (void *)0x0;
  }
  if (index->file != (HANDLE)0x0) {
    _g_io_result = CloseHandle(index->file);
    if (_g_io_result == 0) {
      diag_fatal_file_lasterror(0x52);
    }
    index->file = (void *)0x0;
  }
  return local_5;
}

