int __thiscall idb_browse_set_lines(c1xx_idb *idb,short first_line,short last_line)

{
  uint uVar1;
  uint uVar2;
  c1_idb_browse_entry *pcVar3;
  int iVar4;
  uint *src;
  uint *dst;
  uint uVar5;
  uint uVar6;
  c1_idb_browse_entry new_entry;
  
  uVar1 = (idb->browse_lines).count;
  if (uVar1 <= (idb->file).cursor) {
    uVar5 = (idb->browse_lines).capacity;
    uVar6 = uVar1 + 1;
    if (uVar5 < uVar6) {
      uVar2 = uVar5 * 3 >> 1;
      uVar5 = uVar6;
      if (uVar6 <= uVar2) {
        uVar5 = uVar2;
      }
      pcVar3 = __2_YAPAXI_Z(uVar5 * 0xc);
      if (pcVar3 == (c1_idb_browse_entry *)0x0) goto LAB_10490b74;
      if ((idb->browse_lines).data != (c1_idb_browse_entry *)0x0) {
        uVar2 = 0;
        if ((idb->browse_lines).count != 0) {
          iVar4 = 0;
          do {
            src = (uint *)((int)&((idb->browse_lines).data)->old_first_line + iVar4);
            dst = (uint *)((int)&pcVar3->old_first_line + iVar4);
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
    (idb->browse_lines).count = uVar6;
    pcVar3 = (idb->browse_lines).data + uVar1;
    pcVar3->old_first_line = first_line;
    pcVar3->old_last_line = last_line;
    pcVar3->first_line = new_entry.first_line;
    pcVar3->last_line = new_entry.last_line;
    pcVar3->sbr_offset = -1;
  }
LAB_10490b74:
  (idb->browse_lines).data[(idb->file).cursor].first_line = first_line;
  (idb->browse_lines).data[(idb->file).cursor].last_line = last_line;
  return 1;
}

