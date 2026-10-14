byte __cdecl import_exclude_unless_included(wchar_t *name)

{
  c1_vector *pcVar1;
  int iVar2;
  c1_u8 *pcVar3;
  short sVar4;
  char *pcVar5;
  
  pcVar1 = g_import_includes;
  if (g_import_includes != (c1_vector *)0x0) {
    sVar4 = 0;
    while ((pcVar1 != (c1_vector *)0x0 && (iVar2 = (int)sVar4, iVar2 < (int)(uint)pcVar1->count))) {
      sVar4 = sVar4 + 1;
      iVar2 = wcscmp(name,pcVar1->data[iVar2]);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  pcVar5 = g_import_file_as_written;
  pcVar3 = wide_to_multibyte_arena(name);
  diag_warning(3,0xc0,pcVar3,pcVar5);
  return 1;
}

