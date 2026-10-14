int __thiscall idb_begin_unit(c1xx_idb *idb,int *state_out)

{
  uint uVar1;
  
  uVar1 = idb_check_next_region(idb,1,1);
  *state_out = idb->state;
  return uVar1;
}

