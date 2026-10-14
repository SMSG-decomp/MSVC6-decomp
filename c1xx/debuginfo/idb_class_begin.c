int __thiscall idb_class_begin(c1xx_idb *idb,uint line,int class_ni)

{
  int iVar1;
  int iVar2;
  c1_u32 cVar3;
  c1_idb_class_record *pcVar4;
  c1_idb_class_record *pcVar5;
  c1_idb_class_record *pcVar6;
  bool bVar7;
  c1_idb_class_record new_class;
  
  if ((((idb->include_stack).count == 0) || ((idb->file).untracked != '\0')) || (class_ni == 0)) {
    iVar2 = 1;
  }
  else {
    pcVar6 = &(idb->file).pending_class;
    iVar2 = 5;
    bVar7 = true;
    pcVar4 = pcVar6;
    pcVar5 = &g_idb_empty_class_record;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = pcVar4->class_ni == pcVar5->class_ni;
      pcVar4 = (c1_idb_class_record *)&pcVar4->first_region;
      pcVar5 = (c1_idb_class_record *)&pcVar5->first_region;
    } while (bVar7);
    if (bVar7) {
      new_class.class_ni = class_ni;
      new_class.unk08 = 0;
      new_class.depth = 0;
      new_class.first_region = (idb->file).cursor;
      new_class.change = 0;
      pcVar4 = &new_class;
      for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
        pcVar6->class_ni = pcVar4->class_ni;
        pcVar4 = (c1_idb_class_record *)&pcVar4->first_region;
        pcVar6 = (c1_idb_class_record *)&pcVar6->first_region;
      }
      iVar1 = idb_close_region_changed(idb,line);
      iVar2 = 0;
      if (iVar1 != 0) {
        new_class.unk08 = line & 0xffff;
        (idb->file).current.signature = 0;
        (idb->file).current.length = -1;
        (idb->file).current.start_line = (undefined2)new_class.unk08;
        (idb->file).current.line_count = new_class.unk08._2_2_;
        (idb->file).current.flags = 3;
        (idb->file).current.pad0d[0] = new_class.depth._1_1_;
        (idb->file).current.pad0d[1] = new_class.depth._2_1_;
        (idb->file).current.pad0d[2] = new_class.depth._3_1_;
        return iVar1;
      }
    }
    else {
      cVar3 = (idb->file).pending_class.depth + 1;
      (idb->file).pending_class.depth = cVar3;
      if (cVar3 != 1) {
        return 1;
      }
      iVar1 = idb_close_region(idb,line,0);
      iVar2 = 0;
      if (iVar1 != 0) {
        new_class.unk08 = line & 0xffff;
        (idb->file).current.signature = 0;
        (idb->file).current.length = -1;
        (idb->file).current.start_line = (undefined2)new_class.unk08;
        (idb->file).current.line_count = new_class.unk08._2_2_;
        (idb->file).current.flags = 1;
        (idb->file).current.pad0d[0] = new_class.depth._1_1_;
        (idb->file).current.pad0d[1] = new_class.depth._2_1_;
        (idb->file).current.pad0d[2] = new_class.depth._3_1_;
        return iVar1;
      }
    }
  }
  return iVar2;
}

