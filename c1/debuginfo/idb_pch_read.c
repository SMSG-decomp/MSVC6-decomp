uint __thiscall idb_pch_read(c1_idb_state *idb,int *state_out)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1;
  *state_out = 1;
  if ((idb->include_stack).count != 0) {
    return 0;
  }
  if (idb->pch_generation_seen < idb->pch_generation_used) {
    idb->pch_generation_seen = idb->pch_generation_used;
    uVar3 = (*idb->vtbl->idb_invalidate)(idb);
    uVar3 = uVar3 & 1;
    if (uVar3 == 0) {
      return 0;
    }
  }
  iVar1 = gi_region_record_begin(idb,1);
  if ((iVar1 == 0) || (iVar1 = idb_check_next_region(idb,1,1), iVar1 == 0)) {
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

