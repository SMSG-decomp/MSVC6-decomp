void __fastcall sched_init_cpu_model(c2_function *fn)

{
  int16_t (*paiVar1) [8];
  ushort uVar2;
  int16_t *piVar3;
  uint uVar4;
  int16_t *piVar5;
  int iVar6;
  int iVar7;
  c2_symbol **ppcVar8;
  
  uVar4 = fn->flags;
  g_sched_fn_uses_fp = uVar4 >> 3 & 1;
  uVar2 = (short)g_opt_cpu_target - 3;
  uVar2 = ((short)uVar2 < 0) - 1 & uVar2;
  iVar6 = (int)(short)uVar2;
  _g_sched_cpu_index = CONCAT22(g_sched_cpu_index_2,uVar2);
  g_sched_cpu_word = g_sched_cpu_word_by_cpu[iVar6];
  g_sched_issue_width = g_sched_issue_width_by_cpu[iVar6];
  g_sched_unit_count = g_sched_unit_count_by_cpu[iVar6];
  if (g_sched_fp_mode == 0) {
    paiVar1 = g_sched_priority_weights;
  }
  else {
    paiVar1 = g_sched_priority_weights_fp;
  }
  g_sched_weights = paiVar1[iVar6];
  iVar7 = (int)g_sched_unit_count;
  if (0 < iVar7) {
    piVar3 = &g_sched_units[0].x02;
    piVar5 = &g_sched_cpu_units[iVar6][0].x02;
    do {
      ((c2_sched_unit *)(piVar3 + -1))->capacity = ((c2_sched_unit_model *)(piVar5 + -1))->capacity;
      *piVar3 = *piVar5;
      piVar3[1] = 0;
      *(int32_t *)(piVar3 + 3) = 0;
      piVar3 = piVar3 + 6;
      iVar7 = iVar7 + -1;
      piVar5 = piVar5 + 2;
    } while (iVar7 != 0);
  }
  switch(iVar6) {
  case 0:
    g_sched_latency_table = g_sched_latency_386;
    g_sched_pick_unit_fn = sched_pick_unit_p5;
    break;
  case 1:
    g_sched_latency_table = g_sched_latency_486;
    g_sched_pick_unit_fn = sched_pick_unit_486;
    break;
  case 2:
    g_sched_latency_table = g_sched_latency_p5;
    g_sched_pick_unit_fn = sched_pick_unit_p5;
    break;
  case 3:
    g_sched_latency_table = g_sched_latency_p5;
    g_sched_pick_unit_fn = sched_pick_unit_p6;
  }
  g_sched_fn_omits_frame_pointer = uVar4 >> 4 & 1;
  if ((g_sched_fn_omits_frame_pointer == 0) ||
     ((uVar4 = g_cur_func_sym->attrs & 0x1c, uVar4 != 4 && (uVar4 != 0x10)))) {
    g_sched_fn_returns_float = 0;
  }
  else {
    g_sched_fn_returns_float = 1;
  }
  if (g_sched_fp_mode != 0) {
    g_sched_fp_tos = 8;
    g_sched_fp_peak_depth = 2;
    ppcVar8 = g_sched_fp_stack;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *ppcVar8 = (c2_symbol *)0x0;
      ppcVar8 = ppcVar8 + 1;
    }
    return;
  }
  return;
}

