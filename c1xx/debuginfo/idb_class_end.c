int __thiscall idb_class_end(c1xx_idb *idb,uint line,int class_ni,uint *changed_out)

{
  c1_u32 cVar1;
  c1_mre_file *pcVar2;
  int iVar3;
  uint *src;
  c1_idb_class_record *pcVar4;
  c1_idb_region new_region;
  
  *changed_out = 0;
  if ((((idb->include_stack).count != 0) && ((idb->file).untracked == '\0')) && (class_ni != 0)) {
    cVar1 = (idb->file).pending_class.depth;
    (idb->file).pending_class.depth = cVar1 - 1;
    if (cVar1 == 0) {
      iVar3 = idb_close_region(idb,line,1);
      if (iVar3 != 0) {
        pcVar2 = (idb->file).tracker;
        if (((pcVar2 != (c1_mre_file *)0x0) &&
            (cVar1 = (idb->file).pending_class.change, cVar1 != 0)) &&
           (iVar3 = (*pcVar2->vtbl->note_class_mod)((idb->file).pending_class.class_ni,cVar1),
           iVar3 == 0)) {
          return 1;
        }
        *changed_out = (uint)((idb->file).pending_class.change == 2);
        new_region._8_4_ = line & 0xffff;
        (idb->file).current.signature = 0;
        (idb->file).current.length = -1;
        (idb->file).current.start_line = new_region.start_line;
        (idb->file).current.line_count = new_region.line_count;
        (idb->file).current.flags = '\x01';
        (idb->file).current.pad0d[0] = new_region.pad0d[0];
        (idb->file).current.pad0d[1] = new_region.pad0d[1];
        (idb->file).current.pad0d[2] = new_region.pad0d[2];
        iVar3 = 5;
        src = &g_idb_empty_class_record.class_ni;
        pcVar4 = &(idb->file).pending_class;
        for (; iVar3 != 0; iVar3 = iVar3 + -1) {
          pcVar4->class_ni = *src;
          src = src + 1;
          pcVar4 = (c1_idb_class_record *)&pcVar4->first_region;
        }
      }
    }
    else if ((cVar1 == 1) && (iVar3 = idb_close_region_changed(idb,line), iVar3 != 0)) {
      new_region._8_4_ = line & 0xffff;
      (idb->file).current.signature = 0;
      (idb->file).current.length = -1;
      (idb->file).current.start_line = new_region.start_line;
      (idb->file).current.line_count = new_region.line_count;
      (idb->file).current.flags = '\x03';
      (idb->file).current.pad0d[0] = new_region.pad0d[0];
      (idb->file).current.pad0d[1] = new_region.pad0d[1];
      (idb->file).current.pad0d[2] = new_region.pad0d[2];
      return 1;
    }
  }
  return 1;
}

