uint32_t __fastcall sched_unit_busy_cycles(c2_sched_node *n)

{
  uint uVar1;
  
  if ((n->tuple != (c2_tuple *)0x0) && (uVar1 = n->tuple->op, uVar1 < 0x144)) {
    return g_sched_latency_table[uVar1].busy_cycles;
  }
  return 0;
}

