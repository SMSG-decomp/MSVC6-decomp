void __thiscall idb_begin_unit(c1_idb_state *idb,int *state)

{
  idb_check_next_region(idb,1,1);
  *state = idb->state;
  return;
}

