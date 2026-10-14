int __fastcall sched_window_is_float_heavy(c2_tuple *first,c2_tuple *end)

{
  uint uVar1;
  int32_t iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  
  iVar4 = 0;
  iVar3 = 0;
  local_c = 0;
  if (first != end) {
    do {
      if (((first->flags & 1) != 0) && (iVar3 = iVar3 + 1, (first->type & 0xf000) == 0x4000)) {
        uVar1 = first->op;
        iVar4 = iVar4 + 1;
        if (uVar1 < 0x144) {
          iVar5 = g_sched_latency_table[uVar1].busy_cycles;
          iVar2 = g_sched_latency_table[uVar1].latency;
        }
        else {
          iVar5 = 0;
          iVar2 = 0;
        }
        if (iVar5 < iVar2) {
          local_c = local_c + 1;
        }
      }
      first = first->next;
    } while (first != end);
    if ((0 < local_c) && ((double)iVar3 * 0.5 < (double)iVar4)) {
      return 1;
    }
  }
  return 0;
}

