int __thiscall idb_browse_region(c1_idb_state *idb,uint index,void **entry)

{
  if ((idb->browse_regions).count <= index) {
    *entry = (void *)0x0;
    return 0;
  }
  *entry = (idb->browse_regions).data + index;
  return 1;
}

