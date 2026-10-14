int __thiscall idb_begin_unit_no_check(c1xx_idb *idb,int *state_out)

{
  uint uVar1;
  
  uVar1 = idb_check_next_region(idb,0,1);
  *state_out = 1;
  return uVar1;
}

