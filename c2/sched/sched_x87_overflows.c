int __fastcall sched_x87_overflows(c2_sched_node *n)

{
  int iVar1;
  
  if (g_sched_fp_depth < 7) {
    return 0;
  }
  iVar1 = x87_stack_effect(n->tuple);
  return (uint)(8 < iVar1 + g_sched_fp_depth);
}

