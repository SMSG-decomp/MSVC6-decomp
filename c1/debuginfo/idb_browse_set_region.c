int __thiscall idb_browse_set_region(c1_idb_state *idb,int first_line,int last_line,int value)

{
  (*idb->vtbl->idb_browse_set_lines)(idb,(short)first_line,(short)last_line);
  (idb->browse_regions).data[(idb->file).cursor].sbr_offset = value;
  return 1;
}

