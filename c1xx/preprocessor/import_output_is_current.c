byte __cdecl import_output_is_current(char *tlb,char *output,int *tlb_mtime)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte output_stat [28];
  int local_ac;
  byte tlb_stat [28];
  int local_88;
  char local_80 [128];
  
  if (*tlb_mtime == 0) {
    iVar1 = stat(tlb,tlb_stat);
    if (iVar1 != 0) {
      *tlb_mtime = 0;
      return 0;
    }
    *tlb_mtime = local_88;
  }
  iVar1 = file_open_read_retry(output);
  if (iVar1 != -1) {
    iVar2 = fstat(iVar1,output_stat);
    if ((iVar2 == 0) &&
       (uVar3 = *tlb_mtime - local_ac >> 0x1f, (int)((*tlb_mtime - local_ac ^ uVar3) - uVar3) < 3))
    {
      iVar2 = _read(iVar1,local_80,g_import_banner_length);
      _close(iVar1);
      if (iVar2 == g_import_banner_length) {
        iVar1 = strncmp(local_80,(char *)&g_import_banner,g_import_banner_length);
        if (iVar1 == 0) {
          return 1;
        }
      }
    }
    else {
      _close(iVar1);
    }
  }
  return 0;
}

