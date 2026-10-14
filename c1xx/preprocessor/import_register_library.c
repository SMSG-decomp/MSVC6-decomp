void __cdecl import_register_library(char *path)

{
  c1_u8 *item;
  c1_u8 *_Dest;
  wchar_t *szFile;
  long err;
  int iVar1;
  size_t sVar2;
  wchar_t **ppwVar3;
  int *piVar4;
  int *local_8;
  wchar_t *pwStack_4;
  
  if (g_import_ole_initialized == '\0') {
    import_init_ole(&g_import_ole_initialized);
  }
  szFile = multibyte_to_wide_arena(path);
  err = LoadTypeLib(szFile,&local_8);
  if (err < 0) {
    diag_fatal_file(err,0x53,0x166,g_import_file_as_written);
  }
  ppwVar3 = &pwStack_4;
  iVar1 = (**(code **)(*local_8 + 0x1c))();
  piVar4 = local_8;
  if (iVar1 < 0) {
    diag_fatal_file(iVar1,0x54,0x166,g_import_file_as_written);
    piVar4 = local_8;
  }
  if (g_imported_libraries == (c1_vector *)0x0) {
    g_imported_libraries = vector_new(0,0);
  }
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x14;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(wchar_t **)item = *ppwVar3;
  *(wchar_t **)(item + 4) = ppwVar3[1];
  *(wchar_t **)(item + 8) = ppwVar3[2];
  *(wchar_t **)(item + 0xc) = ppwVar3[3];
  if (g_import_no_namespace != 0) {
    item[0x10] = '\0';
    item[0x11] = '\0';
    item[0x12] = '\0';
    item[0x13] = '\0';
    goto LAB_104a1b8e;
  }
  pwStack_4 = (wchar_t *)0x0;
  if (g_import_namespace == (wchar_t *)0x0) {
    iVar1 = (**(code **)(*piVar4 + 0x24))(piVar4,0xffffffff,&pwStack_4,0,0,0);
    if (iVar1 < 0) {
      diag_fatal_file(iVar1,0x54,0x166,g_import_file_as_written);
    }
    g_import_namespace = import_apply_rename(pwStack_4);
    if (g_import_namespace != (wchar_t *)0x0) goto LAB_104a1c15;
  }
  else {
LAB_104a1c15:
    sVar2 = wcslen(g_import_namespace);
    _Dest = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + (sVar2 * 2 + 5 & 0xfffffffc);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_u8 **)(item + 0x10) = _Dest;
    wcscpy((wchar_t *)_Dest,g_import_namespace);
  }
  SysFreeString(pwStack_4);
LAB_104a1b8e:
  vector_push(g_imported_libraries,item);
  (**(code **)(*piVar4 + 0x30))(piVar4);
  (**(code **)(*ppwVar3 + 4))(ppwVar3);
  return;
}

