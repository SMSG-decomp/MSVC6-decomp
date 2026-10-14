uint32_t __fastcall sched_window_worth_scheduling(c2_tuple *first,c2_tuple *end)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (((g_sched_fp_mode == 0) || (iVar1 = sched_window_is_float_heavy(first,end), iVar1 != 0)) &&
     (first->op != 0x1b5)) {
    for (; first != end; first = first->next) {
      if ((first->flags & 1) != 0) {
        iVar2 = iVar2 + 1;
      }
      if (1 < iVar2) {
        return 1;
      }
    }
  }
  return 0;
}

