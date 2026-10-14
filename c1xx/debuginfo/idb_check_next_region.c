uint __thiscall idb_check_next_region(c1xx_idb *idb,int check,int unused)

{
  uint uVar1;
  uint uVar2;
  c1_idb_region *pcVar3;
  c1_idb_region stored_copy;
  
  uVar1 = 1;
  uVar2 = (idb->file).cursor;
  idb->state = 5;
  if ((uVar2 < (idb->file).regions.count) && (check != 0)) {
    pcVar3 = (idb->file).regions.data + uVar2;
    stored_copy.signature = pcVar3->signature;
    stored_copy.length = pcVar3->length;
    stored_copy.start_line = pcVar3->start_line;
    stored_copy.line_count = pcVar3->line_count;
    stored_copy.flags = pcVar3->flags;
    stored_copy.pad0d[0] = pcVar3->pad0d[0];
    stored_copy.pad0d[1] = pcVar3->pad0d[1];
    stored_copy.pad0d[2] = pcVar3->pad0d[2];
    uVar2 = (*idb->source_tracker->vtbl->sign_next)
                      (idb->source_tracker,pcVar3->length,(int *)&stored_copy,&stored_copy.length);
    uVar2 = uVar2 & 1;
    uVar1 = 0;
    if (uVar2 != 0) {
      if ((pcVar3->signature == stored_copy.signature) && (pcVar3->length == stored_copy.length)) {
        idb->state = 1;
        return uVar2;
      }
      uVar1 = (*idb->vtbl->idb_invalidate)(idb);
      uVar1 = uVar2 & uVar1;
    }
  }
  return uVar1;
}

