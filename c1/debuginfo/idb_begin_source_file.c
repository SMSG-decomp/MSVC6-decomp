int __fastcall idb_begin_source_file(c1_idb_state *idb)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  fe_idb_browse_entry *pfVar4;
  uint *src_words;
  uint uVar5;
  uint *dst_words;
  
  iVar2 = gi_region_record_begin(idb,1);
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = (idb->file).cursor;
  uVar5 = (idb->browse_regions).capacity;
  if (uVar5 < uVar1) {
    uVar3 = uVar5 * 3 >> 1;
    uVar5 = uVar1;
    if (uVar1 <= uVar3) {
      uVar5 = uVar3;
    }
    pfVar4 = __2_YAPAXI_Z(uVar5 * 0xc);
    if (pfVar4 == (fe_idb_browse_entry *)0x0) {
      return 0;
    }
    if ((idb->browse_regions).data != (fe_idb_browse_entry *)0x0) {
      uVar3 = 0;
      if ((idb->browse_regions).count != 0) {
        iVar2 = 0;
        do {
          dst_words = (uint *)((int)&pfVar4->old_first_line + iVar2);
          src_words = (uint *)((int)&((idb->browse_regions).data)->old_first_line + iVar2);
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 0xc;
          *dst_words = *src_words;
          dst_words[1] = src_words[1];
          dst_words[2] = src_words[2];
        } while (uVar3 < (idb->browse_regions).count);
      }
      __3_YAXPAX_Z((idb->browse_regions).data);
    }
    (idb->browse_regions).data = pfVar4;
    (idb->browse_regions).capacity = uVar5;
  }
  (idb->browse_regions).count = uVar1;
  return 1;
}

