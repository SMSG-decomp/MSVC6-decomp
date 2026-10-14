int __thiscall idb_browse_set_lines(c1_idb_state *idb,short first_line,short last_line)

{
  uint uVar1;
  uint uVar2;
  fe_idb_browse_entry *pfVar3;
  int iVar4;
  uint *src_words;
  uint *dst_words;
  uint uVar5;
  uint uVar6;
  fe_idb_browse_entry appended;
  
  uVar1 = (idb->browse_regions).count;
  if (uVar1 <= (idb->file).cursor) {
    uVar5 = (idb->browse_regions).capacity;
    uVar6 = uVar1 + 1;
    if (uVar5 < uVar6) {
      uVar2 = uVar5 * 3 >> 1;
      uVar5 = uVar6;
      if (uVar6 <= uVar2) {
        uVar5 = uVar2;
      }
      pfVar3 = __2_YAPAXI_Z(uVar5 * 0xc);
      if (pfVar3 == (fe_idb_browse_entry *)0x0) goto LAB_10648250;
      if ((idb->browse_regions).data != (fe_idb_browse_entry *)0x0) {
        uVar2 = 0;
        if ((idb->browse_regions).count != 0) {
          iVar4 = 0;
          do {
            src_words = (uint *)((int)&((idb->browse_regions).data)->old_first_line + iVar4);
            dst_words = (uint *)((int)&pfVar3->old_first_line + iVar4);
            uVar2 = uVar2 + 1;
            iVar4 = iVar4 + 0xc;
            *dst_words = *src_words;
            dst_words[1] = src_words[1];
            dst_words[2] = src_words[2];
          } while (uVar2 < (idb->browse_regions).count);
        }
        __3_YAXPAX_Z((idb->browse_regions).data);
      }
      (idb->browse_regions).data = pfVar3;
      (idb->browse_regions).capacity = uVar5;
    }
    (idb->browse_regions).count = uVar6;
    pfVar3 = (idb->browse_regions).data + uVar1;
    pfVar3->old_first_line = first_line;
    pfVar3->old_last_line = last_line;
    pfVar3->first_line = appended.first_line;
    pfVar3->last_line = appended.last_line;
    pfVar3->sbr_offset = -1;
  }
LAB_10648250:
  (idb->browse_regions).data[(idb->file).cursor].first_line = first_line;
  (idb->browse_regions).data[(idb->file).cursor].last_line = last_line;
  return 1;
}

