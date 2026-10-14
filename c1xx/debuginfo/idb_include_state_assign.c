c1_idb_include_state * __thiscall
idb_include_state_assign(c1_idb_include_state *state,c1_idb_include_state *src)

{
  c1_u16 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_idb_region *pcVar5;
  c1_u16 *pcVar6;
  int iVar7;
  uint uVar8;
  c1_u32 cVar9;
  c1_u32 *src_entry;
  c1_idb_class_record *pcVar10;
  c1_u32 *dst_entry;
  c1_idb_class_record *pcVar11;
  
  if (src != state) {
    if ((state->regions).capacity < (src->regions).count) {
      pcVar5 = (state->regions).data;
      if (pcVar5 != (c1_idb_region *)0x0) {
        __3_YAXPAX_Z(pcVar5);
      }
      cVar9 = (src->regions).count;
      (state->regions).capacity = cVar9;
      pcVar5 = __2_YAPAXI_Z(cVar9 << 4);
      if (pcVar5 == (c1_idb_region *)0x0) {
        pcVar5 = (c1_idb_region *)0x0;
      }
      else if (-1 < (int)(cVar9 - 1)) {
        pcVar6 = &pcVar5->start_line;
        do {
          ((c1_idb_region *)(pcVar6 + -4))->signature = 0;
          *(int *)(pcVar6 + -2) = -1;
          *pcVar6 = 0;
          pcVar6[1] = 0;
          *(c1_u8 *)(pcVar6 + 2) = '\x18';
          pcVar6 = pcVar6 + 8;
          cVar9 = cVar9 - 1;
        } while (cVar9 != 0);
      }
      (state->regions).data = pcVar5;
      if (pcVar5 == (c1_idb_region *)0x0) {
        (state->regions).capacity = 0;
        (state->regions).count = 0;
        goto LAB_104912c6;
      }
    }
    cVar9 = (src->regions).count;
    uVar8 = 0;
    (state->regions).count = cVar9;
    if (cVar9 != 0) {
      iVar7 = 0;
      do {
        src_entry = (c1_u32 *)(((src->regions).data)->pad0d + iVar7 + -0xd);
        dst_entry = (c1_u32 *)(((state->regions).data)->pad0d + iVar7 + -0xd);
        uVar8 = uVar8 + 1;
        iVar7 = iVar7 + 0x10;
        *dst_entry = *src_entry;
        dst_entry[1] = src_entry[1];
        dst_entry[2] = src_entry[2];
        dst_entry[3] = src_entry[3];
      } while (uVar8 < (state->regions).count);
    }
  }
LAB_104912c6:
  state->cursor = src->cursor;
  (state->current).signature = (src->current).signature;
  (state->current).length = (src->current).length;
  cVar1 = (src->current).line_count;
  (state->current).start_line = (src->current).start_line;
  (state->current).line_count = cVar1;
  cVar2 = (src->current).pad0d[0];
  cVar3 = (src->current).pad0d[1];
  cVar4 = (src->current).pad0d[2];
  (state->current).flags = (src->current).flags;
  (state->current).pad0d[0] = cVar2;
  (state->current).pad0d[1] = cVar3;
  (state->current).pad0d[2] = cVar4;
  pcVar10 = &src->pending_class;
  pcVar11 = &state->pending_class;
  for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
    pcVar11->class_ni = pcVar10->class_ni;
    pcVar10 = (c1_idb_class_record *)&pcVar10->first_region;
    pcVar11 = (c1_idb_class_record *)&pcVar11->first_region;
  }
  state->tracker = src->tracker;
  state->name_ni = src->name_ni;
  state->mtime = src->mtime;
  state->unk40 = src->unk40;
  state->changed = src->changed;
  state->untracked = src->untracked;
  return state;
}

