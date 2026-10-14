void __fastcall sched_fp_swap_slots(int a,int b)

{
  c2_symbol *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = a + g_sched_fp_tos;
  iVar2 = g_sched_fp_tos + b;
  pcVar1 = g_sched_fp_stack[iVar3];
  g_sched_fp_stack[iVar3] = g_sched_fp_stack[iVar2];
  g_sched_fp_stack[iVar2] = pcVar1;
  return;
}

