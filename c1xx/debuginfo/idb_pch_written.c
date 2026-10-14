uint __thiscall idb_pch_written(c1xx_idb *idb,int *state_out)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *state_out = 1;
  if ((idb->include_stack).count != 0) {
    return 0;
  }
  uVar1 = gi_region_record_begin(idb,1);
  uVar3 = 0;
  if ((uVar1 & 1) != 0) {
    if (idb->invalidated != 0) {
      iVar2 = idb->pch_generation + 1;
      idb->pch_generation = iVar2;
      idb->regions_pch_generation = iVar2;
    }
    uVar3 = idb_check_next_region(idb,1,1);
    uVar3 = uVar1 & 1 & uVar3;
    if (uVar3 != 0) {
      *state_out = idb->state;
    }
  }
  return uVar3;
}

