byte __fastcall pch_image_map_blocks(int asked,int *index,int zero,byte result,int moved)

{
  int *reader;
  bool bVar1;
  int iVar2;
  int iVar3;
  time_t tVar4;
  
  for (iVar3 = asked + -2; -1 < iVar3; iVar3 = iVar3 + -1) {
    (**(code **)(**(int **)(index[2] + iVar3 * 4) + 0xc))();
  }
  iVar3 = index[7];
  index[7] = zero;
  index[8] = iVar3;
  bVar1 = false;
  iVar3 = 0;
  if (zero < *index) {
    do {
      iVar2 = (**(code **)(**(int **)(index[2] + iVar3 * 4) + 4))(index[6]);
      if (iVar2 != 6) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *index);
    if (bVar1) {
      if (g_opt_BMOVE != '\0') {
        tVar4 = time((time_t *)zero);
        srand((uint)tVar4);
      }
      iVar3 = 0;
      if (zero < *index) {
        do {
          reader = *(int **)(index[2] + iVar3 * 4);
          if ((reader[3] != 6) &&
             (iVar2 = (**(code **)(*reader + 8))(reader,(void *)index[6],zero), iVar2 == 5)) {
            moved = moved + 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *index);
        if (moved != zero) {
          pch_image_relocate((c1xx_pch_image *)index,moved);
          result = 1;
        }
      }
    }
  }
  if ((HANDLE)index[8] != (HANDLE)zero) {
    _g_io_result = CloseHandle((HANDLE)index[8]);
    if (_g_io_result == zero) {
      diag_fatal_file_lasterror(0x52,0x158,(char *)index[4]);
    }
    index[8] = zero;
  }
  if ((HANDLE)index[6] != (HANDLE)zero) {
    _g_io_result = CloseHandle((HANDLE)index[6]);
    if (_g_io_result == zero) {
      diag_fatal_file_lasterror(0x52,0x158,(char *)index[4]);
    }
    index[6] = zero;
  }
  return result;
}

