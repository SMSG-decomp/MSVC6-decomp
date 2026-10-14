uint __thiscall
idb_function_begin(c1_idb_state *idb,uint close_header_region,uint start_line,int force,
                  int *state_out,int *stored_count_out,short *stored_start_out,int *matched_out)

{
  byte bVar1;
  uint uVar2;
  fe_idb_region *pfVar3;
  char cVar4;
  fe_idb_region region;
  
  idb->helper_called = '\0';
  *matched_out = 0;
  if ((idb->include_stack).count != 0) {
    *state_out = 1;
    if (close_header_region != 0) {
      uVar2 = idb_function_region_in_header(idb,close_header_region,start_line,force);
      return uVar2;
    }
    return 1;
  }
  idb->in_function = '\x01';
  close_header_region = gi_region_record_begin(idb,1);
  if (close_header_region != 0) {
    idb->state = 2;
    *state_out = 2;
    *stored_count_out = 0;
    *stored_start_out = 0;
    if ((idb->recompile == 0) && (force == 0)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    region._8_4_ = start_line & 0xffff;
    (idb->file).current.signature = 0;
    region._12_4_ = CONCAT31(region.pad0d,cVar4 << 4) | 2;
    (idb->file).current.length = -1;
    idb->open_conditionals = 0;
    (idb->file).current.start_line = region.start_line;
    (idb->file).current.line_count = region.line_count;
    (idb->file).current.flags = region.flags;
    (idb->file).current.pad0d[0] = region.pad0d[0];
    (idb->file).current.pad0d[1] = region.pad0d[1];
    (idb->file).current.pad0d[2] = region.pad0d[2];
    uVar2 = (idb->file).cursor;
    if (uVar2 < (idb->file).regions.count) {
      pfVar3 = (idb->file).regions.data + uVar2;
      region.signature = pfVar3->signature;
      region.length = pfVar3->length;
      region.start_line = pfVar3->start_line;
      region.line_count = pfVar3->line_count;
      region.flags = pfVar3->flags;
      region.pad0d[0] = pfVar3->pad0d[0];
      region.pad0d[1] = pfVar3->pad0d[1];
      region.pad0d[2] = pfVar3->pad0d[2];
      bVar1 = (*idb->tracker->vtbl->seek)
                        (idb->tracker,pfVar3->length,&region.signature,&region.length);
      close_header_region = close_header_region & bVar1;
      if (close_header_region != 0) {
        if ((pfVar3->signature == region.signature) && (pfVar3->length == region.length)) {
          *matched_out = 1;
          if (((pfVar3->flags & 0x18) == 0) &&
             (((pfVar3->flags & 0x20) == 0 || (pfVar3->start_line == (ushort)start_line)))) {
            idb->force_tracking = 1;
            idb->state = 4;
            *state_out = 4;
            *stored_count_out = pfVar3->length;
            *stored_start_out = pfVar3->line_count;
            idb->helper_called = (idb->file).regions.data[(idb->file).cursor].flags >> 7;
            g_idb_outside_function = '\0';
            return close_header_region;
          }
        }
        else if ((pfVar3->flags & 8) != 0) {
          uVar2 = (*idb->vtbl->idb_invalidate)(idb);
          close_header_region = close_header_region & uVar2;
        }
      }
    }
  }
  g_idb_outside_function = '\0';
  return close_header_region;
}

