uint __thiscall
idb_function_region_end(c1xx_idb *idb,int class_ni,uint line,int macro_depth,int *changed_out)

{
  int *changed;
  uint uVar1;
  c1_idb_region new_region;
  
  changed = changed_out;
  *changed_out = 0;
  changed_out = (int *)0x0;
  uVar1 = idb_region_close(idb,line,0,changed,(int *)&changed_out);
  new_region._8_4_ = line & 0xffff;
  (idb->file).current.signature = 0;
  (idb->file).current.length = -1;
  (idb->file).current.start_line = new_region.start_line;
  (idb->file).current.line_count = new_region.line_count;
  (idb->file).current.flags = '\x01';
  (idb->file).current.pad0d[0] = new_region.pad0d[0];
  (idb->file).current.pad0d[1] = new_region.pad0d[1];
  (idb->file).current.pad0d[2] = new_region.pad0d[2];
  return uVar1;
}

