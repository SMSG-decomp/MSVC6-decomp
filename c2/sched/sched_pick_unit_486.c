int16_t __fastcall sched_pick_unit_486(c2_sched_node *n,c2_sched_node **picks,int nsel)

{
  uint unit;
  int iVar1;
  
  unit = n->pipe & 7;
  if ((g_sched_fp_mode != 0) && (iVar1 = sched_x87_overflows(n), iVar1 != 0)) {
    return -1;
  }
  iVar1 = sched_unit_free(unit);
  if (iVar1 == 0) {
    return -1;
  }
  return (int16_t)unit;
}

