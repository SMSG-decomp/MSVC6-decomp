void __fastcall sched_set_edge_latency(c2_sched_edge *edge,c2_symbol *sym,c2_symbol *sym2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(byte)edge->from->latency;
  switch(g_sched_cpu_index) {
  case 0:
  case 1:
    iVar1 = sched_agi_penalty(edge,sym2);
    uVar2 = uVar2 + iVar1;
    break;
  case 2:
    iVar1 = sched_is_esp_push_pop_chain(sym,edge);
    if (iVar1 != 0) {
      uVar2 = 0;
      goto switchD_1073b284_default;
    }
    iVar1 = sched_agi_penalty(edge,sym2);
    uVar2 = uVar2 + iVar1;
    iVar1 = sched_fp_store_latency_penalty(edge);
    goto LAB_1073b2ac;
  case 3:
    break;
  default:
    goto switchD_1073b284_default;
  }
  iVar1 = sched_extra_latency_for_order(sym,sym2);
LAB_1073b2ac:
  uVar2 = uVar2 + iVar1;
switchD_1073b284_default:
  if (edge->from->tuple->op == 0x162) {
    edge->latency = 0;
    return;
  }
  if ((int)(uint)edge->latency < (int)uVar2) {
    edge->latency = (uint16_t)uVar2;
  }
  return;
}

