void __fastcall sched_fp_depth_update(c2_sched_node *n)

{
  int iVar1;
  
  if (g_sched_fp_mode != 0) {
    iVar1 = x87_stack_effect(n->tuple);
    g_sched_fp_depth = g_sched_fp_depth + (short)iVar1;
  }
  return;
}

