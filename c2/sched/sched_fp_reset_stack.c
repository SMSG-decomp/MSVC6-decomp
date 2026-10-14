void sched_fp_reset_stack(void)

{
  int iVar1;
  c2_symbol **ppcVar2;
  
  g_sched_fp_tos = 8;
  g_sched_fp_peak_depth = 2;
  ppcVar2 = g_sched_fp_stack;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar2 = (c2_symbol *)0x0;
    ppcVar2 = ppcVar2 + 1;
  }
  return;
}

