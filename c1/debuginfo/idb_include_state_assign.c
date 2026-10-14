fe_idb_include_state * __thiscall
idb_include_state_assign(fe_idb_include_state *state,fe_idb_include_state *from)

{
  ushort uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  fe_idb_region *pfVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  fe_idb_region *src_region;
  fe_idb_class_record *pfVar10;
  fe_idb_region *dst_region;
  fe_idb_class_record *pfVar11;
  
  if (from != state) {
    if ((state->regions).capacity < (from->regions).count) {
      pfVar5 = (state->regions).data;
      if (pfVar5 != (fe_idb_region *)0x0) {
        __3_YAXPAX_Z(pfVar5);
      }
      uVar9 = (from->regions).count;
      (state->regions).capacity = uVar9;
      pfVar5 = __2_YAPAXI_Z(uVar9 << 4);
      if (pfVar5 == (fe_idb_region *)0x0) {
        pfVar5 = (fe_idb_region *)0x0;
      }
      else if (-1 < (int)(uVar9 - 1)) {
        puVar6 = &pfVar5->start_line;
        do {
          ((fe_idb_region *)(puVar6 + -4))->signature = 0;
          *(int *)(puVar6 + -2) = -1;
          *puVar6 = 0;
          puVar6[1] = 0;
          *(uchar *)(puVar6 + 2) = '\x18';
          puVar6 = puVar6 + 8;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      (state->regions).data = pfVar5;
      if (pfVar5 == (fe_idb_region *)0x0) {
        (state->regions).capacity = 0;
        (state->regions).count = 0;
        goto LAB_106489e2;
      }
    }
    uVar9 = (from->regions).count;
    uVar8 = 0;
    (state->regions).count = uVar9;
    if (uVar9 != 0) {
      iVar7 = 0;
      do {
        src_region = (fe_idb_region *)(((from->regions).data)->pad0d + iVar7 + -0xd);
        dst_region = (fe_idb_region *)(((state->regions).data)->pad0d + iVar7 + -0xd);
        uVar8 = uVar8 + 1;
        iVar7 = iVar7 + 0x10;
        dst_region->signature = src_region->signature;
        dst_region->length = src_region->length;
        uVar1 = src_region->line_count;
        dst_region->start_line = src_region->start_line;
        dst_region->line_count = uVar1;
        uVar2 = src_region->pad0d[0];
        uVar3 = src_region->pad0d[1];
        uVar4 = src_region->pad0d[2];
        dst_region->flags = src_region->flags;
        dst_region->pad0d[0] = uVar2;
        dst_region->pad0d[1] = uVar3;
        dst_region->pad0d[2] = uVar4;
      } while (uVar8 < (state->regions).count);
    }
  }
LAB_106489e2:
  state->cursor = from->cursor;
  (state->current).signature = (from->current).signature;
  (state->current).length = (from->current).length;
  uVar1 = (from->current).line_count;
  (state->current).start_line = (from->current).start_line;
  (state->current).line_count = uVar1;
  uVar2 = (from->current).pad0d[0];
  uVar3 = (from->current).pad0d[1];
  uVar4 = (from->current).pad0d[2];
  (state->current).flags = (from->current).flags;
  (state->current).pad0d[0] = uVar2;
  (state->current).pad0d[1] = uVar3;
  (state->current).pad0d[2] = uVar4;
  pfVar10 = &from->pending_class;
  pfVar11 = &state->pending_class;
  for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
    pfVar11->class_ni = pfVar10->class_ni;
    pfVar10 = (fe_idb_class_record *)&pfVar10->first_region;
    pfVar11 = (fe_idb_class_record *)&pfVar11->first_region;
  }
  state->tracker = from->tracker;
  state->name_ni = from->name_ni;
  state->mtime = from->mtime;
  state->unk40 = from->unk40;
  state->changed = from->changed;
  state->untracked = from->untracked;
  return state;
}

