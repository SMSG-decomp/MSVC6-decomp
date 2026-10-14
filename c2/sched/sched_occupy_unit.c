void __fastcall sched_occupy_unit(c2_sched_node *n)

{
  uint uVar1;
  uint32_t uVar2;
  
  uVar1 = n->pipe & 7;
  uVar2 = sched_unit_busy_cycles(n);
  if (n->tuple->op == 0x46) {
    g_sched_fmul_busy = 2;
  }
  if (g_sched_units[uVar1].busy < 0) {
    g_sched_units[uVar1].busy = 0;
  }
  g_sched_units[uVar1].busy = g_sched_units[uVar1].busy + uVar2;
  return;
}

