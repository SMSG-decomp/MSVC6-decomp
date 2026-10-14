void __cdecl import_collect_dependencies(void *typeinfo,void *typeattr,int index,void *graph)

{
  int iVar1;
  void *typeinfo_00;
  void *pvVar2;
  void *graph_00;
  byte bVar3;
  bool bVar4;
  long lVar5;
  ushort uVar6;
  ulong local_4;
  
  graph_00 = graph;
  pvVar2 = typeattr;
  typeinfo_00 = typeinfo;
  iVar1 = *(int *)((int)typeattr + 0x28);
  if (((iVar1 == 4) && ((*(byte *)((int)typeattr + 0x36) & 0x40) != 0)) &&
     (g_import_no_dual_interfaces == 0)) {
    lVar5 = (**(code **)(*(int *)typeinfo + 0x20))(typeinfo,0xffffffff,&local_4);
    if (lVar5 < 0) {
      diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
    }
    lVar5 = (**(code **)(*(int *)typeinfo_00 + 0x38))(typeinfo_00,local_4,&typeinfo);
    if (lVar5 < 0) {
      diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
    }
    lVar5 = (**(code **)(*(int *)typeinfo + 0xc))(typeinfo,&typeattr);
    if (lVar5 < 0) {
      diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
    }
    import_collect_dependencies(typeinfo,typeattr,index,graph);
    (**(code **)(*(int *)typeinfo + 0x4c))(typeinfo,typeattr);
    (**(code **)(*(int *)typeinfo + 8))(typeinfo);
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 == 3) {
      if (*(short *)((int)typeattr + 0x30) == 0) {
        return;
      }
      lVar5 = (**(code **)(*(int *)typeinfo + 0x20))(typeinfo,0,(ulong *)&typeattr);
      if (lVar5 < 0) {
        diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
      }
      bVar3 = import_get_ref_type_info(typeinfo_00,(uint)typeattr,&typeinfo);
      if (bVar3 == 0) {
        return;
      }
      bVar4 = import_typeinfo_in_current_library(typeinfo,&local_4);
      if (bVar4) {
        import_depgraph_add_edge(graph,local_4,index);
      }
      (**(code **)(*(int *)typeinfo + 8))(typeinfo);
      return;
    }
    if (iVar1 != 7) {
      return;
    }
  }
  uVar6 = 0;
  if (*(short *)((int)typeattr + 0x2e) != 0) {
    do {
      lVar5 = (**(code **)(*(int *)typeinfo_00 + 0x18))(typeinfo_00,(uint)uVar6,&typeinfo);
      if (lVar5 < 0) {
        diag_fatal_file(lVar5,0x54,0x166,g_import_file_as_written);
      }
      if ((*(short *)((int)typeinfo + 0x10) == 0x1d) &&
         (bVar3 = import_get_ref_type_info(typeinfo_00,*(uint *)((int)typeinfo + 0xc),&graph),
         bVar3 != 0)) {
        bVar4 = import_typeinfo_in_current_library(graph,(uint *)&typeattr);
        if (bVar4) {
          import_depgraph_add_edge(graph_00,(int)typeattr,index);
        }
        (**(code **)(*(int *)graph + 8))(graph);
      }
      (**(code **)(*(int *)typeinfo_00 + 0x54))(typeinfo_00,typeinfo);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)((int)pvVar2 + 0x2e));
  }
  return;
}

