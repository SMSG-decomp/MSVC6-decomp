void sched_init_cpu_model_case_0(int zero,uint32_t fn_flags)

{
  uint uVar1;
  int iVar2;
  c2_symbol **ppcVar3;
  
  g_sched_latency_table = g_sched_latency_386;
  g_sched_pick_unit_fn = sched_pick_unit_p5;
  g_sched_fn_omits_frame_pointer = fn_flags >> 4 & 1;
  g_sched_fn_returns_float = zero;
  if ((g_sched_fn_omits_frame_pointer != 0) &&
     ((uVar1 = g_cur_func_sym->attrs & 0x1c, uVar1 == 4 || (uVar1 == 0x10)))) {
    g_sched_fn_returns_float = 1;
  }
  if (g_sched_fp_mode != zero) {
    g_sched_fp_tos = 8;
    g_sched_fp_peak_depth = 2;
    ppcVar3 = g_sched_fp_stack;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppcVar3 = (c2_symbol *)0x0;
      ppcVar3 = ppcVar3 + 1;
    }
    return;
  }
  return;
}

