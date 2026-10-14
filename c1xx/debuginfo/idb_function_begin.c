uint __thiscall
idb_function_begin(c1xx_idb *idb,uint class_ni,uint line,int macro_depth,int *state_out,
                  int *length_out,short *line_count_out,int *matched_out)

{
  uint uVar1;
  c1_idb_region *pcVar2;
  char cVar3;
  c1_idb_region region_tmp;
  
  idb->helper_called = '\0';
  *matched_out = 0;
  if ((idb->include_stack).count != 0) {
    *state_out = 1;
    if (class_ni != 0) {
      uVar1 = idb_function_region_in_header(idb,class_ni,line,macro_depth);
      return uVar1;
    }
    return 1;
  }
  idb->in_function = '\x01';
  class_ni = gi_region_record_begin(idb,1);
  if (class_ni != 0) {
    idb->state = 2;
    *state_out = 2;
    *length_out = 0;
    *line_count_out = 0;
    if ((idb->force_recompile == 0) && (macro_depth == 0)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    region_tmp._8_4_ = line & 0xffff;
    (idb->file).current.signature = 0;
    region_tmp._12_4_ = CONCAT31(region_tmp.pad0d,cVar3 << 4) | 2;
    (idb->file).current.length = -1;
    idb->cond_depth = 0;
    (idb->file).current.start_line = region_tmp.start_line;
    (idb->file).current.line_count = region_tmp.line_count;
    (idb->file).current.flags = region_tmp.flags;
    (idb->file).current.pad0d[0] = region_tmp.pad0d[0];
    (idb->file).current.pad0d[1] = region_tmp.pad0d[1];
    (idb->file).current.pad0d[2] = region_tmp.pad0d[2];
    uVar1 = (idb->file).cursor;
    if (uVar1 < (idb->file).regions.count) {
      pcVar2 = (idb->file).regions.data + uVar1;
      region_tmp.signature = pcVar2->signature;
      region_tmp.length = pcVar2->length;
      region_tmp.start_line = pcVar2->start_line;
      region_tmp.line_count = pcVar2->line_count;
      region_tmp.flags = pcVar2->flags;
      region_tmp.pad0d[0] = pcVar2->pad0d[0];
      region_tmp.pad0d[1] = pcVar2->pad0d[1];
      region_tmp.pad0d[2] = pcVar2->pad0d[2];
      uVar1 = (*idb->source_tracker->vtbl->sign_next)(pcVar2->length,&region_tmp,&region_tmp.length)
      ;
      class_ni = class_ni & uVar1 & 0xff;
      if (class_ni != 0) {
        if ((pcVar2->signature == region_tmp.signature) && (pcVar2->length == region_tmp.length)) {
          *matched_out = 1;
          if (((pcVar2->flags & 0x18) == 0) &&
             (((pcVar2->flags & 0x20) == 0 || (pcVar2->start_line == (c1_u16)line)))) {
            idb->reused = 1;
            idb->state = 4;
            *state_out = 4;
            *length_out = pcVar2->length;
            *line_count_out = pcVar2->line_count;
            idb->helper_called = (idb->file).regions.data[(idb->file).cursor].flags >> 7;
            g_idb_outside_function = '\0';
            return class_ni;
          }
        }
        else if ((pcVar2->flags & 8) != 0) {
          uVar1 = (*idb->vtbl->idb_invalidate)(idb);
          class_ni = class_ni & uVar1;
        }
      }
    }
  }
  g_idb_outside_function = '\0';
  return class_ni;
}

