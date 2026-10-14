bool __cdecl import_typeinfo_in_current_library(void *typeinfo,uint *index)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  c1_u32 *pcVar5;
  bool bVar6;
  bool bVar7;
  
  lVar1 = (**(code **)(*(int *)typeinfo + 0x48))(typeinfo,&typeinfo,index);
  if (lVar1 < 0) {
    diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
  }
  lVar1 = (**(code **)(*(int *)typeinfo + 0x1c))(typeinfo,&index);
  if (lVar1 < 0) {
    diag_fatal_file(lVar1,0x54,0x166,g_import_file_as_written);
  }
  iVar2 = 0x10;
  bVar6 = false;
  iVar3 = 0;
  bVar7 = true;
  puVar4 = index;
  pcVar5 = g_import_libid;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = (byte)*puVar4 < (byte)*pcVar5;
    bVar7 = (byte)*puVar4 == (byte)*pcVar5;
    puVar4 = (uint *)((int)puVar4 + 1);
    pcVar5 = (c1_u32 *)((int)pcVar5 + 1);
  } while (bVar7);
  if (!bVar7) {
    iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
  }
  (**(code **)(*(int *)typeinfo + 0x30))(typeinfo,index);
  (**(code **)(*(int *)typeinfo + 8))(typeinfo);
  return iVar3 == 0;
}

