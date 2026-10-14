int16_t __fastcall sched_pick_unit_p5(c2_sched_node *n,c2_sched_node **picks,int nsel)

{
  uint unit;
  int iVar1;
  int iVar2;
  
  unit = n->pipe & 7;
  if (((n->tuple->op != 0x46) || (g_sched_fmul_busy < 1)) &&
     ((g_sched_fp_mode == 0 || (iVar1 = sched_x87_overflows(n), iVar1 == 0)))) {
    if ((int)g_sched_unit_count <= (int)unit) {
      iVar1 = 0;
      if (0 < g_sched_unit_count) {
        do {
          iVar2 = sched_unit_free(iVar1);
          if (iVar2 == 0) {
            return -1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < g_sched_unit_count);
      }
      return 0;
    }
    if (nsel == 0) {
      iVar1 = sched_unit_free(unit);
      if ((iVar1 != 0) && (iVar1 = sched_unit_free(unit + 1), iVar1 != 0)) {
        return (int16_t)unit;
      }
    }
    else {
      iVar1 = sched_can_pair_uv(*picks,n);
      if (iVar1 != 0) {
        return (int16_t)unit + 1;
      }
    }
  }
  return -1;
}

