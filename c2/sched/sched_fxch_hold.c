int __fastcall
sched_fxch_hold(c2_sched_node *n,int cycle,c2_sched_node *ready_head,c2_tuple *emit_tail)

{
  c2_sched_node *pcVar1;
  
  if (g_sched_fp_mode == 0) {
    if ((((emit_tail->op == 0x5f) || ((emit_tail->op == 0x162 && (emit_tail->prev->op == 0x5f)))) &&
        (g_sched_cpu_index == 2)) &&
       (((1 << (byte)(n->tuple->type >> 0xc) & 0xeU) != 0 && (ready_head != (c2_sched_node *)0x0))))
    {
      while ((ready_head->tuple == (c2_tuple *)0x0 ||
             ((((ready_head->tuple->type & 0xf000) != 0x4000 || (1 < g_sched_units[2].busy)) ||
              (cycle + 1U < (uint)ready_head->earliest))))) {
        ready_head = ready_head->ready_next;
        if (ready_head == (c2_sched_node *)0x0) {
          return 0;
        }
      }
      return 1;
    }
  }
  else {
    for (pcVar1 = n->ready_next; pcVar1 != (c2_sched_node *)0x0; pcVar1 = pcVar1->ready_next) {
      if ((pcVar1->tuple == (c2_tuple *)0x0) && ((ushort)pcVar1->index < (ushort)n->index)) {
        if (((1 << (byte)(uRam0000000a >> 0xc) & 0xeU) != 0) &&
           ((n->tuple->type & 0xf000) == 0x4000)) {
          return 1;
        }
        if (((uRam0000000a & 0xf000) == 0x4000) &&
           ((1 << (byte)(n->tuple->type >> 0xc) & 0xeU) != 0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

