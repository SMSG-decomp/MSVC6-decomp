void sched_advance_cycle(void)

{
  int32_t *piVar1;
  int iVar2;
  
  iVar2 = (int)g_sched_unit_count;
  if (0 < iVar2) {
    piVar1 = &g_sched_units[0].busy;
    do {
      iVar2 = iVar2 + -1;
      *piVar1 = *piVar1 + -1;
      piVar1 = piVar1 + 3;
    } while (iVar2 != 0);
  }
  g_sched_fmul_busy = g_sched_fmul_busy + -1;
  return;
}

