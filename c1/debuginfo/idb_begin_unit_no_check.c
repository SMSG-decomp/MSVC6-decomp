void __thiscall idb_begin_unit_no_check(c1_idb_state *idb,int *state)

{
  idb_check_next_region(idb,0,1);
  *state = 1;
  return;
}

