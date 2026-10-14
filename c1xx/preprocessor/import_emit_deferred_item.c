void __cdecl import_emit_deferred_item(void *typelib,int index)

{
  long lVar1;
  wchar_t *name;
  void *pvStack_4;
  
  lVar1 = (**(code **)(*(int *)typelib + 0x10))(typelib,index,&typelib);
  if (lVar1 < 0) {
    diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
  }
  lVar1 = (**(code **)(*(int *)typelib + 0xc))(typelib,&pvStack_4);
  if (lVar1 < 0) {
    diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
  }
  lVar1 = (**(code **)(*(int *)typelib + 0x30))
                    (typelib,-1,(wchar_t **)&index,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
  if (lVar1 < 0) {
    diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
  }
  name = import_apply_rename((wchar_t *)index);
  import_emit_type_item(typelib,pvStack_4,name);
  SysFreeString((wchar_t *)index);
  (**(code **)(*(int *)typelib + 0x4c))(typelib,pvStack_4);
  (**(code **)(*(int *)typelib + 8))(typelib);
  return;
}

