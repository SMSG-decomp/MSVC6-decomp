int __thiscall idb_check_next_region(c1_idb_state *idb,int check,int unused)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  fe_idb_region *pfVar4;
  fe_idb_region region;
  
  uVar2 = 1;
  uVar3 = (idb->file).cursor;
  idb->state = 5;
  if ((uVar3 < (idb->file).regions.count) && (check != 0)) {
    pfVar4 = (idb->file).regions.data + uVar3;
    region.signature = pfVar4->signature;
    region.length = pfVar4->length;
    region.start_line = pfVar4->start_line;
    region.line_count = pfVar4->line_count;
    region.flags = pfVar4->flags;
    region.pad0d[0] = pfVar4->pad0d[0];
    region.pad0d[1] = pfVar4->pad0d[1];
    region.pad0d[2] = pfVar4->pad0d[2];
    bVar1 = (*idb->tracker->vtbl->seek)
                      (idb->tracker,pfVar4->length,&region.signature,&region.length);
    uVar2 = bVar1 & 1;
    if ((bVar1 & 1) != 0) {
      if ((pfVar4->signature == region.signature) && (pfVar4->length == region.length)) {
        idb->state = 1;
        return uVar2;
      }
      uVar3 = (*idb->vtbl->idb_invalidate)(idb);
      uVar2 = uVar2 & uVar3;
    }
  }
  return uVar2;
}

