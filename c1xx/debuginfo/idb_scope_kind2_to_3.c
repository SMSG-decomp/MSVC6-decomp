int __thiscall idb_scope_kind2_to_3(c1xx_idb *idb,uint line,int macro_depth)

{
  int iVar1;
  c1_idb_class_record *pcVar2;
  c1_idb_class_record *pcVar3;
  bool bVar4;
  c1_idb_region new_region;
  
  bVar4 = true;
  iVar1 = 5;
  pcVar2 = &(idb->file).pending_class;
  pcVar3 = &g_idb_empty_class_record;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = pcVar2->class_ni == pcVar3->class_ni;
    pcVar2 = (c1_idb_class_record *)&pcVar2->first_region;
    pcVar3 = (c1_idb_class_record *)&pcVar3->first_region;
  } while (bVar4);
  if (((!bVar4) && ((idb->file).pending_class.depth == 0)) && (((idb->file).current.flags & 7) == 2)
     ) {
    iVar1 = idb_close_region(idb,line,0);
    new_region._8_4_ = line & 0xffff;
    (idb->file).current.signature = 0;
    (idb->file).current.length = -1;
    (idb->file).current.start_line = new_region.start_line;
    (idb->file).current.line_count = new_region.line_count;
    (idb->file).current.flags = '\x03';
    (idb->file).current.pad0d[0] = new_region.pad0d[0];
    (idb->file).current.pad0d[1] = new_region.pad0d[1];
    (idb->file).current.pad0d[2] = new_region.pad0d[2];
    return iVar1;
  }
  return 1;
}

