uint __thiscall
idb_function_end(c1xx_idb *idb,uint class_ni,uint line,int macro_depth,int *state_out,
                int *changed_out)

{
  c1_idb_region *pcVar1;
  c1_u32 cVar2;
  c1_u16 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_u8 cVar6;
  uint uVar7;
  int iVar8;
  c1_idb_region *pcVar9;
  uint *src_region;
  uint uVar10;
  uint *dst_region_3;
  uint *dst_region;
  uint *dst_region_2;
  
  g_idb_outside_function = '\x01';
  *changed_out = 0;
  idb->in_function = '\0';
  if ((((idb->include_stack).count != 0) || (iVar8 = idb->state, iVar8 == 1)) || (iVar8 == 5)) {
    *state_out = idb->state;
    if (class_ni != 0) {
      uVar7 = idb_function_region_end(idb,class_ni,line,macro_depth,changed_out);
      return uVar7;
    }
    return 1;
  }
  changed_out = (int *)0x1;
  if (iVar8 == 4) {
    (idb->file).regions.data[(idb->file).cursor].start_line = (idb->file).current.start_line;
    (*idb->source_tracker->vtbl->reset)();
    goto LAB_1048ede6;
  }
  if (idb->cond_depth != 0) {
    dst_region_2 = (uint *)&(idb->file).current.flags;
    *(byte *)dst_region_2 = (byte)*dst_region_2 | 8;
  }
  pcVar1 = &(idb->file).current;
  uVar7 = (*idb->source_tracker->vtbl->take)(pcVar1,&(idb->file).current.length);
  changed_out = (int *)(uVar7 & 0xff);
  if (changed_out == (int *)0x0) goto LAB_1048ede6;
  uVar7 = (idb->file).cursor;
  (idb->file).current.line_count = (short)line - (idb->file).current.start_line;
  if (uVar7 < (idb->file).regions.count) {
    if ((((idb->file).current.flags & 8) == 0) || (((idb->file).regions.data[uVar7].flags & 8) != 0)
       ) {
      pcVar9 = (idb->file).regions.data + uVar7;
      pcVar9->signature = pcVar1->signature;
      pcVar9->length = (idb->file).current.length;
      cVar3 = (idb->file).current.line_count;
      pcVar9->start_line = (idb->file).current.start_line;
      pcVar9->line_count = cVar3;
      cVar4 = (idb->file).current.pad0d[0];
      cVar5 = (idb->file).current.pad0d[1];
      cVar6 = (idb->file).current.pad0d[2];
      pcVar9->flags = (idb->file).current.flags;
      pcVar9->pad0d[0] = cVar4;
      pcVar9->pad0d[1] = cVar5;
      pcVar9->pad0d[2] = cVar6;
      goto LAB_1048ede6;
    }
    uVar7 = (*idb->vtbl->idb_invalidate)(idb);
    changed_out = (int *)((uint)changed_out & uVar7);
    iVar8 = region_array_set_size(&(idb->file).regions,(idb->file).regions.count + 1);
    if (iVar8 != 0) {
      pcVar9 = (idb->file).regions.data + ((idb->file).regions.count - 1);
      goto LAB_1048eeff;
    }
LAB_1048f02b:
    uVar7 = 0;
  }
  else {
    cVar2 = (idb->file).regions.count;
    uVar7 = (idb->file).regions.capacity;
    uVar10 = cVar2 + 1;
    if (uVar7 < uVar10) {
      uVar7 = uVar7 * 3 >> 1;
      line = uVar10;
      if (uVar10 <= uVar7) {
        line = uVar7;
      }
      pcVar9 = __2_YAPAXI_Z(line << 4);
      if (pcVar9 == (c1_idb_region *)0x0) goto LAB_1048f02b;
      vector_constructor_iterator(pcVar9,0x10,line,gi_region_entry_init_empty);
      iVar8 = 0;
      if ((idb->file).regions.data != (c1_idb_region *)0x0) {
        class_ni = 0;
        if ((idb->file).regions.count != 0) {
          do {
            dst_region_3 = (uint *)(pcVar9->pad0d + iVar8 + -0xd);
            src_region = (uint *)(((idb->file).regions.data)->pad0d + iVar8 + -0xd);
            iVar8 = iVar8 + 0x10;
            *dst_region_3 = *src_region;
            dst_region_3[1] = src_region[1];
            dst_region_3[2] = src_region[2];
            dst_region_3[3] = src_region[3];
            class_ni = class_ni + 1;
          } while (class_ni < (idb->file).regions.count);
        }
        __3_YAXPAX_Z((idb->file).regions.data);
      }
      (idb->file).regions.data = pcVar9;
      (idb->file).regions.capacity = line;
    }
    pcVar9 = (idb->file).regions.data;
    (idb->file).regions.count = uVar10;
    pcVar9 = pcVar9 + cVar2;
LAB_1048eeff:
    pcVar9->signature = pcVar1->signature;
    pcVar9->length = (idb->file).current.length;
    cVar3 = (idb->file).current.line_count;
    pcVar9->start_line = (idb->file).current.start_line;
    pcVar9->line_count = cVar3;
    cVar4 = (idb->file).current.pad0d[0];
    cVar5 = (idb->file).current.pad0d[1];
    cVar6 = (idb->file).current.pad0d[2];
    uVar7 = 1;
    pcVar9->flags = (idb->file).current.flags;
    pcVar9->pad0d[0] = cVar4;
    pcVar9->pad0d[1] = cVar5;
    pcVar9->pad0d[2] = cVar6;
  }
  changed_out = (int *)((uint)changed_out & uVar7);
LAB_1048ede6:
  dst_region = (uint *)&(idb->file).regions.data[(idb->file).cursor].flags;
  *(byte *)dst_region = idb->helper_called << 7 | (byte)*dst_region & 0x7f;
  (*g_il_emitter->vtbl->region_boundary)();
  (idb->file).cursor = (idb->file).cursor + 1;
  if (changed_out != (int *)0x0) {
    changed_out = (int *)idb_check_next_region(idb,1,1);
    *state_out = idb->state;
  }
  return (uint)changed_out;
}

