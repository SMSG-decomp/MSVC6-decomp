int __fastcall idb_begin_source_file(c1xx_idb *idb)

{
  uint uVar1;
  c1_mre_file *pcVar2;
  int iVar3;
  uint uVar4;
  c1_idb_browse_entry *pcVar5;
  uint *src;
  uint uVar6;
  uint *dst;
  
  iVar3 = gi_region_record_begin(idb,1);
  if (iVar3 == 0) {
    return 0;
  }
  uVar1 = (idb->file).cursor;
  uVar6 = (idb->browse_lines).capacity;
  if (uVar6 < uVar1) {
    uVar4 = uVar6 * 3 >> 1;
    uVar6 = uVar1;
    if (uVar1 <= uVar4) {
      uVar6 = uVar4;
    }
    pcVar5 = __2_YAPAXI_Z(uVar6 * 0xc);
    if (pcVar5 == (c1_idb_browse_entry *)0x0) {
      return 0;
    }
    if ((idb->browse_lines).data != (c1_idb_browse_entry *)0x0) {
      uVar4 = 0;
      if ((idb->browse_lines).count != 0) {
        iVar3 = 0;
        do {
          dst = (uint *)((int)&pcVar5->old_first_line + iVar3);
          src = (uint *)((int)&((idb->browse_lines).data)->old_first_line + iVar3);
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 0xc;
          *dst = *src;
          dst[1] = src[1];
          dst[2] = src[2];
        } while (uVar4 < (idb->browse_lines).count);
      }
      __3_YAXPAX_Z((idb->browse_lines).data);
    }
    (idb->browse_lines).data = pcVar5;
    (idb->browse_lines).capacity = uVar6;
  }
  (idb->browse_lines).count = uVar1;
  pcVar2 = (idb->file).tracker;
  iVar3 = 1;
  if (pcVar2 != (c1_mre_file *)0x0) {
    iVar3 = (*pcVar2->vtbl->note_end_include)((-(uint)(idb->reused != 0) & 0xffffffe0) + 0x20);
  }
  return iVar3;
}

