int __thiscall idb_function_region_in_header(c1xx_idb *idb,uint class_ni,uint line,int macro_depth)

{
  int iVar1;
  c1_idb_region new_region;
  
  iVar1 = idb_close_region_changed(idb,line);
  new_region._8_4_ = line & 0xffff;
  (idb->file).current.signature = 0;
  (idb->file).current.length = -1;
  (idb->file).current.start_line = new_region.start_line;
  (idb->file).current.line_count = new_region.line_count;
  (idb->file).current.flags = '\x02';
  (idb->file).current.pad0d[0] = new_region.pad0d[0];
  (idb->file).current.pad0d[1] = new_region.pad0d[1];
  (idb->file).current.pad0d[2] = new_region.pad0d[2];
  return iVar1;
}

