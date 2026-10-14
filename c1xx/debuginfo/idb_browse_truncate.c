int __fastcall idb_browse_truncate(c1xx_idb *idb)

{
  uint uVar1;
  uint uVar2;
  c1_idb_browse_entry *pcVar3;
  int iVar4;
  uint *src;
  uint uVar5;
  uint *dst;
  
  uVar1 = (idb->file).cursor;
  uVar5 = (idb->browse_lines).capacity;
  if (uVar5 < uVar1) {
    uVar2 = uVar5 * 3 >> 1;
    uVar5 = uVar1;
    if (uVar1 <= uVar2) {
      uVar5 = uVar2;
    }
    pcVar3 = __2_YAPAXI_Z(uVar5 * 0xc);
    if (pcVar3 == (c1_idb_browse_entry *)0x0) {
      return 1;
    }
    if ((idb->browse_lines).data != (c1_idb_browse_entry *)0x0) {
      uVar2 = 0;
      if ((idb->browse_lines).count != 0) {
        iVar4 = 0;
        do {
          dst = (uint *)((int)&pcVar3->old_first_line + iVar4);
          src = (uint *)((int)&((idb->browse_lines).data)->old_first_line + iVar4);
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 0xc;
          *dst = *src;
          dst[1] = src[1];
          dst[2] = src[2];
        } while (uVar2 < (idb->browse_lines).count);
      }
      __3_YAXPAX_Z((idb->browse_lines).data);
    }
    (idb->browse_lines).data = pcVar3;
    (idb->browse_lines).capacity = uVar5;
  }
  (idb->browse_lines).count = uVar1;
  return 1;
}

