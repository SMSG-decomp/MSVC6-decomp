int __thiscall idb_include_leave(c1_idb_state *idb,c1_u16 line)

{
  fe_idb_include_stack *stack;
  uchar *puVar1;
  fe_idb_include_state *pfVar2;
  fe_idb_include_state *pfVar3;
  ushort uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  fe_idb_region *pfVar8;
  ushort *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  fe_idb_region *src_region;
  uint *popped_class_src;
  uint *empty_class_src;
  uint *state_class_src;
  fe_idb_region *dst_region;
  uint *file_class_dst;
  uint *state_class_dst;
  uint *top_class_dst;
  fe_idb_include_state empty_state;
  
  if ((idb->include_stack).count == 0) {
    return 1;
  }
  if ((idb->state != 1) && (idb->state != 5)) {
    puVar1 = &(idb->file).current.flags;
    *puVar1 = *puVar1 | 8;
  }
  stack = &idb->include_stack;
  pfVar3 = &idb->file;
  pfVar2 = stack->data + ((idb->include_stack).count - 1);
  if (pfVar2 != pfVar3) {
    if ((idb->file).regions.capacity < (pfVar2->regions).count) {
      pfVar8 = (pfVar3->regions).data;
      if (pfVar8 != (fe_idb_region *)0x0) {
        __3_YAXPAX_Z(pfVar8);
      }
      uVar12 = (pfVar2->regions).count;
      (idb->file).regions.capacity = uVar12;
      pfVar8 = __2_YAPAXI_Z(uVar12 << 4);
      if (pfVar8 == (fe_idb_region *)0x0) {
        pfVar8 = (fe_idb_region *)0x0;
      }
      else if (-1 < (int)(uVar12 - 1)) {
        puVar9 = &pfVar8->start_line;
        do {
          ((fe_idb_region *)(puVar9 + -4))->signature = 0;
          *(int *)(puVar9 + -2) = -1;
          *puVar9 = 0;
          puVar9[1] = 0;
          *(uchar *)(puVar9 + 2) = '\x18';
          puVar9 = puVar9 + 8;
          uVar12 = uVar12 - 1;
        } while (uVar12 != 0);
      }
      (pfVar3->regions).data = pfVar8;
      if (pfVar8 == (fe_idb_region *)0x0) {
        (idb->file).regions.capacity = 0;
        (idb->file).regions.count = 0;
        goto LAB_10647aee;
      }
    }
    uVar12 = (pfVar2->regions).count;
    uVar11 = 0;
    (idb->file).regions.count = uVar12;
    if (uVar12 != 0) {
      iVar10 = 0;
      do {
        src_region = (fe_idb_region *)(((pfVar2->regions).data)->pad0d + iVar10 + -0xd);
        dst_region = (fe_idb_region *)(((pfVar3->regions).data)->pad0d + iVar10 + -0xd);
        uVar11 = uVar11 + 1;
        iVar10 = iVar10 + 0x10;
        dst_region->signature = src_region->signature;
        dst_region->length = src_region->length;
        uVar4 = src_region->line_count;
        dst_region->start_line = src_region->start_line;
        dst_region->line_count = uVar4;
        uVar5 = src_region->pad0d[0];
        uVar6 = src_region->pad0d[1];
        uVar7 = src_region->pad0d[2];
        dst_region->flags = src_region->flags;
        dst_region->pad0d[0] = uVar5;
        dst_region->pad0d[1] = uVar6;
        dst_region->pad0d[2] = uVar7;
      } while (uVar11 < (idb->file).regions.count);
    }
  }
LAB_10647aee:
  (idb->file).cursor = pfVar2->cursor;
  (idb->file).current.signature = (pfVar2->current).signature;
  (idb->file).current.length = (pfVar2->current).length;
  uVar4 = (pfVar2->current).line_count;
  (idb->file).current.start_line = (pfVar2->current).start_line;
  (idb->file).current.line_count = uVar4;
  uVar5 = (pfVar2->current).pad0d[0];
  uVar6 = (pfVar2->current).pad0d[1];
  uVar7 = (pfVar2->current).pad0d[2];
  (idb->file).current.flags = (pfVar2->current).flags;
  (idb->file).current.pad0d[0] = uVar5;
  (idb->file).current.pad0d[1] = uVar6;
  (idb->file).current.pad0d[2] = uVar7;
  iVar10 = 5;
  popped_class_src = &(pfVar2->pending_class).class_ni;
  file_class_dst = &(idb->file).pending_class.class_ni;
  for (; iVar10 != 0; iVar10 = iVar10 + -1) {
    *file_class_dst = *popped_class_src;
    popped_class_src = popped_class_src + 1;
    file_class_dst = file_class_dst + 1;
  }
  (idb->file).tracker = pfVar2->tracker;
  (idb->file).name_ni = pfVar2->name_ni;
  (idb->file).mtime = pfVar2->mtime;
  (idb->file).unk40 = pfVar2->unk40;
  (idb->file).changed = pfVar2->changed;
  (idb->file).untracked = pfVar2->untracked;
  if ((idb->include_stack).count != 0) {
    empty_state.regions.data = (fe_idb_region *)0x0;
    empty_state.regions.capacity = 0;
    empty_state.regions.count = 0;
    gi_region_entry_init(&empty_state.current,0);
    empty_state.pending_class.class_ni = 0;
    empty_state.pending_class.first_region = 0;
    pfVar3 = stack->data;
    empty_state.pending_class.unk08 = 0;
    empty_state.pending_class.depth = 0;
    empty_state.pending_class.change = 0;
    empty_state.cursor = 0;
    iVar10 = 5;
    empty_class_src = &g_idb_empty_class_record.class_ni;
    state_class_dst = &empty_state.pending_class.class_ni;
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      *state_class_dst = *empty_class_src;
      empty_class_src = empty_class_src + 1;
      state_class_dst = state_class_dst + 1;
    }
    empty_state.tracker = (MREFile *)0x0;
    empty_state.name_ni = 0;
    empty_state.unk40 = 0;
    empty_state.changed = '\0';
    empty_state.untracked = '\0';
    empty_state.mtime = -1;
    pfVar3 = pfVar3 + ((idb->include_stack).count - 1);
    region_array_assign(&pfVar3->regions,&empty_state.regions);
    pfVar3->cursor = empty_state.cursor;
    (pfVar3->current).signature = empty_state.current.signature;
    (pfVar3->current).length = empty_state.current.length;
    (pfVar3->current).start_line = empty_state.current.start_line;
    (pfVar3->current).line_count = empty_state.current.line_count;
    (pfVar3->current).flags = empty_state.current.flags;
    (pfVar3->current).pad0d[0] = empty_state.current.pad0d[0];
    (pfVar3->current).pad0d[1] = empty_state.current.pad0d[1];
    (pfVar3->current).pad0d[2] = empty_state.current.pad0d[2];
    iVar10 = 5;
    state_class_src = &empty_state.pending_class.class_ni;
    top_class_dst = (uint *)(&pfVar3->current + 1);
    for (; iVar10 != 0; iVar10 = iVar10 + -1) {
      *top_class_dst = *state_class_src;
      state_class_src = state_class_src + 1;
      top_class_dst = top_class_dst + 1;
    }
    pfVar3->tracker = empty_state.tracker;
    pfVar3->name_ni = empty_state.name_ni;
    pfVar3->mtime = empty_state.mtime;
    pfVar3->unk40 = empty_state.unk40;
    pfVar3->changed = empty_state.changed;
    pfVar3->untracked = empty_state.untracked;
    pdb_array_destroy((Array_DWORD *)&empty_state);
    idb_include_stack_set_size(stack,(idb->include_stack).count - 1);
  }
  return 1;
}

