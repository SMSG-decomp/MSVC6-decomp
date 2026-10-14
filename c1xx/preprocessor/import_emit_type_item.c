void __cdecl import_emit_type_item(void *typeinfo,void *typeattr,wchar_t *name)

{
  uint uVar1;
  void *pThis;
  long lVar2;
  wchar_t *name_00;
  ulong local_4;
  
  pThis = typeinfo;
  uVar1 = *(uint *)((int)typeattr + 0x28);
  if (uVar1 != 2) {
    if (uVar1 == 4) {
      if (((*(byte *)((int)typeattr + 0x36) & 0x40) != 0) && (g_import_no_dual_interfaces == 0)) {
        lVar2 = (**(code **)(*(int *)typeinfo + 0x20))(typeinfo,0xffffffff,&local_4);
        if (lVar2 < 0) {
          diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
        }
        lVar2 = (**(code **)(*(int *)pThis + 0x38))(pThis,local_4,&typeinfo);
        if (lVar2 < 0) {
          diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
        }
        lVar2 = (**(code **)(*(int *)typeinfo + 0xc))(typeinfo,&typeattr);
        if (lVar2 < 0) {
          diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
        }
        lVar2 = (**(code **)(*(int *)typeinfo + 0x30))
                          (typeinfo,-1,&name,(wchar_t **)0x0,(ulong *)0x0,(wchar_t **)0x0);
        if (lVar2 < 0) {
          diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
        }
        name_00 = import_apply_rename(name);
        import_emit_type_item(typeinfo,typeattr,name_00);
        SysFreeString(name);
        (**(code **)(*(int *)typeinfo + 0x4c))(typeinfo,typeattr);
        (**(code **)(*(int *)typeinfo + 8))(typeinfo);
        return;
      }
    }
    else if (7 < uVar1) {
      return;
    }
    switch(uVar1) {
    case 0:
      import_emit_enum(typeinfo,typeattr,name);
      return;
    case 1:
      import_emit_struct_or_union("struct",typeinfo,typeattr,name);
      return;
    case 3:
      import_emit_interface_struct(typeinfo,typeattr,name);
      return;
    case 4:
      import_emit_dispinterface_struct(typeinfo,typeattr,name);
      return;
    case 5:
      import_emit_coclass(typeinfo,typeattr,name);
      break;
    case 7:
      import_emit_struct_or_union("union",typeinfo,typeattr,name);
      return;
    }
  }
  return;
}

