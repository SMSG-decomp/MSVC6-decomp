void __fastcall sched_set_output_dep_latency(c2_symbol *sym,c2_sched_edge *edge)

{
  uint16_t uVar1;
  uint32_t uVar2;
  int iVar3;
  
  uVar1 = g_sched_output_dep_latency_by_cpu[g_sched_cpu_index];
  uVar2 = edge->from->tuple->op;
  if ((((uVar2 != 0xe) && (edge->to->tuple->op != 0x5f)) && (sym->storage != g_reg_symbols + 0x42))
     && (uVar2 != 0x162)) {
    iVar3 = sched_is_esp_push_pop_chain(sym,edge);
    if ((iVar3 == 0) && ((int)(uint)edge->latency < (int)(short)uVar1)) {
      edge->latency = uVar1;
    }
  }
  return;
}

