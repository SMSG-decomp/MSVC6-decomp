int __thiscall idb_browse_region(c1xx_idb *idb,uint index,c1_idb_browse_entry **entry_out)

{
  if ((idb->browse_lines).count <= index) {
    *entry_out = (c1_idb_browse_entry *)0x0;
    return 0;
  }
  *entry_out = (idb->browse_lines).data + index;
  return 1;
}

