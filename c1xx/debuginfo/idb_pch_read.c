uint __thiscall idb_pch_read(c1xx_idb *idb,int *state_out)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1;
  *state_out = 1;
  if ((idb->include_stack).count != 0) {
    return 0;
  }
  if ((uint)idb->regions_pch_generation < (uint)idb->pch_generation_loaded) {
    idb->regions_pch_generation = idb->pch_generation_loaded;
    uVar3 = (*idb->vtbl->idb_invalidate)(idb);
    uVar3 = uVar3 & 1;
    if (uVar3 == 0) {
      return 0;
    }
  }
  iVar1 = gi_region_record_begin(idb,1);
  if ((iVar1 == 0) || (uVar2 = idb_check_next_region(idb,1,1), uVar2 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  if ((uVar3 & uVar2) != 0) {
    *state_out = idb->state;
  }
  return uVar3 & uVar2;
}

