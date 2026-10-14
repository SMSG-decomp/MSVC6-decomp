void __cdecl import_emit_record_fields(void *typeinfo,void *typeattr,wchar_t *class_name)

{
  int iVar1;
  void *pThis;
  void *pvVar2;
  long lVar3;
  wchar_t *name;
  ushort uVar4;
  
  pvVar2 = typeattr;
  pThis = typeinfo;
  uVar4 = 0;
  iVar1 = *(int *)((int)typeattr + 0x28);
  if (*(short *)((int)typeattr + 0x2e) != 0) {
    do {
      lVar3 = (**(code **)(*(int *)pThis + 0x18))(pThis,(uint)uVar4,&typeattr);
      if (lVar3 < 0) {
        diag_fatal_file(lVar3,0x54,0x166,g_import_file_as_written);
      }
      lVar3 = (**(code **)(*(int *)pThis + 0x30))
                        (pThis,*(long *)typeattr,&typeinfo,(wchar_t **)0x0,(ulong *)0x0,
                         (wchar_t **)0x0);
      if (lVar3 < 0) {
        diag_fatal_file(lVar3,0x54,0x166,g_import_file_as_written);
      }
      name = import_apply_rename(typeinfo);
      if (iVar1 == 4) {
        import_emit_dispatch_property(pThis,typeattr,class_name,name);
      }
      else {
        import_text_puts(g_import_items,"    ");
        import_write_typedesc(g_import_items,(void *)((int)typeattr + 0xc),pThis,name,0);
        import_text_puts(g_import_items,";\n");
      }
      SysFreeString(typeinfo);
      (**(code **)(*(int *)pThis + 0x54))(pThis,typeattr);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(ushort *)((int)pvVar2 + 0x2e));
  }
  return;
}

