uint __thiscall idb_function_body_end(c1xx_idb *idb,uint line,int macro_depth,int *changed_out)

{
  int *changed;
  uint uVar1;
  int iVar2;
  c1_idb_class_record *pcVar3;
  c1_idb_class_record *pcVar4;
  bool bVar5;
  c1_idb_region new_region;
  
  changed = changed_out;
  bVar5 = true;
  iVar2 = 5;
  pcVar3 = &(idb->file).pending_class;
  pcVar4 = &g_idb_empty_class_record;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = pcVar3->class_ni == pcVar4->class_ni;
    pcVar3 = (c1_idb_class_record *)&pcVar3->first_region;
    pcVar4 = (c1_idb_class_record *)&pcVar4->first_region;
  } while (bVar5);
  if ((!bVar5) && ((idb->file).pending_class.depth == 0)) {
    changed_out = (int *)0x0;
    *changed = 0;
    uVar1 = idb_region_close(idb,line,0,changed,(int *)&changed_out);
    new_region._8_4_ = line & 0xffff;
    (idb->file).current.signature = 0;
    (idb->file).current.length = -1;
    (idb->file).current.start_line = new_region.start_line;
    (idb->file).current.line_count = new_region.line_count;
    (idb->file).current.flags = '\x03';
    (idb->file).current.pad0d[0] = new_region.pad0d[0];
    (idb->file).current.pad0d[1] = new_region.pad0d[1];
    (idb->file).current.pad0d[2] = new_region.pad0d[2];
    return uVar1;
  }
  return 1;
}

