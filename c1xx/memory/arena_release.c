void __fastcall arena_release(c1_arena *a)

{
  BOOL BVar1;
  int iVar2;
  DWORD DVar3;
  char *pcVar4;
  char local_100 [256];
  
  if (a->base != (c1_u8 *)0x0) {
    if ((0 < (int)a->committed) && (BVar1 = VirtualFree(a->base,a->committed,0x4000), BVar1 == 0)) {
      DVar3 = GetLastError();
      iVar2 = 0x100;
      pcVar4 = misc_string_get(0x38e);
      format_snprintf(local_100,pcVar4,iVar2,DVar3);
      diag_write_stderr(local_100);
    }
    if (a->mapped == '\0') {
      iVar2 = VirtualFree(a->base,0,0x8000);
    }
    else {
      iVar2 = UnmapViewOfFile(a->base);
    }
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      iVar2 = 0x100;
      pcVar4 = misc_string_get(0x38e);
      format_snprintf(local_100,pcVar4,iVar2,DVar3);
      diag_write_stderr(local_100);
    }
    a->base = (c1_u8 *)0x0;
  }
  return;
}

