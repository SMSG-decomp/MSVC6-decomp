int __fastcall idb_browse_table_reset(c1xx_idb *idb)

{
  ushort *entry_cell;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((idb->browse_lines).count != 0) {
    iVar2 = 0;
    do {
      entry_cell = (ushort *)((int)&((idb->browse_lines).data)->old_first_line + iVar2);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0xc;
      *entry_cell = entry_cell[2];
      entry_cell[1] = entry_cell[3];
      entry_cell[4] = 0xffff;
      entry_cell[5] = 0xffff;
    } while (uVar1 < (idb->browse_lines).count);
    return 1;
  }
  return 1;
}

