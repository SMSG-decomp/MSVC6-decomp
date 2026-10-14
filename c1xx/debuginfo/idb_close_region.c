int __thiscall idb_close_region(c1xx_idb *idb,uint line,int consume_following)

{
  uint uVar1;
  int local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = 0;
  uVar1 = idb_region_close(idb,line,consume_following,&local_8,&local_4);
  if (uVar1 == 0) {
    return 0;
  }
  if (local_8 != 0) {
    (idb->file).pending_class.change = (idb->file).pending_class.change | 2 - (local_4 != 0);
  }
  return 1;
}

