int __cdecl file_open_read_retry(char *file)

{
  char *_Filename;
  int iVar1;
  int *piVar2;
  int iVar3;
  
  _Filename = file_name_for_FAT(file);
  iVar3 = 1;
  while( true ) {
    if (1 < iVar3) {
      return -1;
    }
    iVar1 = _sopen(_Filename,0x8000,0x20);
    if (iVar1 != -1) break;
    piVar2 = _errno();
    if (*piVar2 != 0x18) {
      return -1;
    }
    include_close_outer_handle();
    iVar3 = iVar3 + 1;
  }
  return iVar1;
}

