int __thiscall idb_pch_written(c1_idb_state *idb,int *state)

{
  uint uVar1;
  c1_u32 cVar2;
  uint uVar3;
  
  *state = 1;
  if ((idb->include_stack).count != 0) {
    return 0;
  }
  uVar1 = gi_region_record_begin(idb,1);
  uVar3 = 0;
  if ((uVar1 & 1) != 0) {
    if (idb->invalidated != 0) {
      cVar2 = idb->pch_generation + 1;
      idb->pch_generation = cVar2;
      idb->pch_generation_seen = cVar2;
    }
    uVar3 = idb_check_next_region(idb,1,1);
    uVar3 = uVar1 & 1 & uVar3;
    if (uVar3 != 0) {
      *state = idb->state;
    }
  }
  return uVar3;
}

