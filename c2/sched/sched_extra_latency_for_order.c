int __fastcall sched_extra_latency_for_order(c2_symbol *sym,c2_symbol *sym2)

{
  if (sym->size < sym2->size) {
    return (int)g_sched_partial_reg_latency_by_cpu[g_sched_cpu_index];
  }
  return 0;
}

