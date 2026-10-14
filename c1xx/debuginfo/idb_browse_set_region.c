int __thiscall idb_browse_set_region(c1xx_idb *idb,int first_line,int last_line,int sbr_offset)

{
  (*idb->vtbl->idb_browse_set_lines)(idb,(short)first_line,(short)last_line);
  (idb->browse_lines).data[(idb->file).cursor].sbr_offset = sbr_offset;
  return 1;
}

