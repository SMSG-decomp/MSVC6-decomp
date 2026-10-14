int __fastcall idb_browse_table_reset(c1_idb_state *idb)

{
  fe_idb_browse_entry *region;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((idb->browse_regions).count != 0) {
    iVar2 = 0;
    do {
      region = (fe_idb_browse_entry *)((int)&((idb->browse_regions).data)->old_first_line + iVar2);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0xc;
      region->old_first_line = region->first_line;
      region->old_last_line = region->last_line;
      region->sbr_offset = -1;
    } while (uVar1 < (idb->browse_regions).count);
    return 1;
  }
  return 1;
}

