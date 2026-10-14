int16_t __fastcall sched_pick_unit_p6(c2_sched_node *n,c2_sched_node **picks,int nsel)

{
  uint unit;
  int iVar1;
  int iVar2;
  
  unit = n->pipe & 7;
  if ((g_sched_fp_mode == 0) || (iVar1 = sched_x87_overflows(n), iVar1 == 0)) {
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
    iVar1 = 0;
    if (0 < nsel) {
      do {
        if (((*picks)->pipe & 7) == unit) {
          return -1;
        }
        iVar1 = iVar1 + 1;
        picks = picks + 1;
      } while (iVar1 < nsel);
    }
    iVar1 = sched_unit_free(unit);
    if (iVar1 != 0) {
      return (int16_t)unit;
    }
  }
  return -1;
}

