void sched_reset_units(void)

{
  int32_t *piVar1;
  int iVar2;
  
  iVar2 = (int)g_sched_unit_count;
  if (0 < iVar2) {
    piVar1 = &g_sched_units[0].busy;
    do {
      *piVar1 = 0;
      piVar1 = piVar1 + 3;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

