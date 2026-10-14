void __cdecl import_write_cross_referenced_libraries(void)

{
  void *guid;
  c1_vector *pcVar1;
  int iVar2;
  long lVar3;
  short sVar4;
  wchar_t *local_54;
  wchar_t awStack_50 [40];
  
  if (((g_import_implementation_only == 0) && (g_import_cross_referenced_libs != (c1_vector *)0x0))
     && (g_import_cross_referenced_libs->count != 0)) {
    fprintf((FILE *)g_import_tlh_file,"\n//\n// Cross-referenced type libraries:\n//\n");
    pcVar1 = g_import_cross_referenced_libs;
    sVar4 = 0;
    while ((pcVar1 != (c1_vector *)0x0 && (iVar2 = (int)sVar4, iVar2 < (int)(uint)pcVar1->count))) {
      sVar4 = sVar4 + 1;
      guid = pcVar1->data[iVar2];
      lVar3 = QueryPathOfRegTypeLib
                        (guid,*(ushort *)((int)guid + 0x18),*(ushort *)((int)guid + 0x1a),
                         *(ulong *)((int)guid + 0x10),&local_54);
      if (lVar3 < 0) {
        iVar2 = StringFromGUID2(guid,awStack_50,0x4e);
        if (iVar2 != 0) {
          fprintf((FILE *)g_import_tlh_file,"//  #import unregistered typelib, LIBID %S\n",
                  awStack_50);
        }
      }
      else {
        fprintf((FILE *)g_import_tlh_file,"//  #import \"%S\"\n",local_54);
        SysFreeString(local_54);
      }
    }
    fprintf((FILE *)g_import_tlh_file,"//\n");
  }
  return;
}

