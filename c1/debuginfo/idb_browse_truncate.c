int __fastcall idb_browse_truncate(c1_idb_state *idb)

{
  uint uVar1;
  uint uVar2;
  fe_idb_browse_entry *pfVar3;
  int iVar4;
  uint *src_words;
  uint uVar5;
  uint *dst_words;
  
  uVar1 = (idb->file).cursor;
  uVar5 = (idb->browse_regions).capacity;
  if (uVar5 < uVar1) {
    uVar2 = uVar5 * 3 >> 1;
    uVar5 = uVar1;
    if (uVar1 <= uVar2) {
      uVar5 = uVar2;
    }
    pfVar3 = __2_YAPAXI_Z(uVar5 * 0xc);
    if (pfVar3 == (fe_idb_browse_entry *)0x0) {
      return 1;
    }
    if ((idb->browse_regions).data != (fe_idb_browse_entry *)0x0) {
      uVar2 = 0;
      if ((idb->browse_regions).count != 0) {
        iVar4 = 0;
        do {
          dst_words = (uint *)((int)&pfVar3->old_first_line + iVar4);
          src_words = (uint *)((int)&((idb->browse_regions).data)->old_first_line + iVar4);
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
  (idb->browse_regions).count = uVar1;
  return 1;
}

