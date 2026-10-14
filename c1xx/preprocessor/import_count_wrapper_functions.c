int __cdecl import_count_wrapper_functions(void *typelib,uint count)

{
  void *pThis;
  uint uVar1;
  long lVar2;
  int iVar3;
  uint index;
  int iVar4;
  ulong uStack_8;
  int *piStack_4;
  
  uVar1 = count;
  pThis = typelib;
  iVar4 = 0;
  index = 0;
  if (count == 0) {
    return 0;
  }
  do {
    lVar2 = (**(code **)(*(int *)pThis + 0x10))(pThis,index,(void **)&count);
    if (lVar2 < 0) {
      diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
    }
    lVar2 = (**(code **)(*(int *)count + 0xc))((void *)count,&typelib);
    if (lVar2 < 0) {
      diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
    }
    iVar3 = *(int *)((int)typelib + 0x28);
    if (((iVar3 == 4) && ((*(byte *)((int)typelib + 0x36) & 0x40) != 0)) &&
       (g_import_no_dual_interfaces == 0)) {
      lVar2 = (**(code **)(*(int *)count + 0x20))((void *)count,0xffffffff,&uStack_8);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      lVar2 = (**(code **)(*(int *)count + 0x38))((void *)count,uStack_8,&piStack_4);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      (**(code **)(*(int *)count + 0x4c))((void *)count,typelib);
      (**(code **)(*(int *)count + 8))((void *)count);
      count = (uint)piStack_4;
      lVar2 = (**(code **)(*piStack_4 + 0xc))(piStack_4,&typelib);
      if (lVar2 < 0) {
        diag_fatal_file(lVar2,0x54,0x166,g_import_file_as_written);
      }
      iVar3 = *(int *)((int)typelib + 0x28);
    }
    if (iVar3 == 3) {
      if (g_import_raw_interfaces_only == 0) {
        iVar4 = iVar4 + (uint)*(ushort *)((int)typelib + 0x2c);
      }
    }
    else if (iVar3 == 4) {
      if (g_import_raw_interfaces_only == 0) {
        iVar4 = (uint)*(ushort *)((int)typelib + 0x2c) + iVar4 +
                (uint)*(ushort *)((int)typelib + 0x2e) * 2;
      }
      if (g_import_raw_dispinterfaces != 0) {
        iVar4 = (uint)*(ushort *)((int)typelib + 0x2c) + iVar4 +
                (uint)*(ushort *)((int)typelib + 0x2e) * 2;
      }
    }
    (**(code **)(*(int *)count + 0x4c))((void *)count,typelib);
    (**(code **)(*(int *)count + 8))((void *)count);
    index = index + 1;
  } while (index < uVar1);
  return iVar4;
}

