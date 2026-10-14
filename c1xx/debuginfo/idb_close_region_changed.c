int __thiscall idb_close_region_changed(c1xx_idb *idb,uint line)

{
  uint uVar1;
  int local_8 [2];
  
  local_8[0] = 0;
  local_8[1] = 0;
  uVar1 = idb_region_close(idb,line,0,local_8,local_8 + 1);
  if (uVar1 == 0) {
    return 0;
  }
  if (local_8[0] != 0) {
    (idb->file).changed = '\x01';
  }
  return 1;
}

