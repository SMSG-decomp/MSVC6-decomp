wchar_t * __cdecl import_apply_rename(wchar_t *name)

{
  c1_vector *pcVar1;
  int iVar2;
  short sVar3;
  wchar_t **rename_pair;
  
  pcVar1 = g_import_renames;
  if (g_import_renames == (c1_vector *)0x0) {
    return name;
  }
  sVar3 = 0;
  while ((pcVar1 != (c1_vector *)0x0 && (iVar2 = (int)sVar3, iVar2 < (int)(uint)pcVar1->count))) {
    sVar3 = sVar3 + 1;
    rename_pair = pcVar1->data[iVar2];
    iVar2 = wcscmp(*rename_pair,name);
    if (iVar2 == 0) {
      return rename_pair[1];
    }
  }
  return name;
}

