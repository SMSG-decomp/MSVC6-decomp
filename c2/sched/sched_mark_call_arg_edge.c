void __fastcall sched_mark_call_arg_edge(c2_sched_edge *e)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  
  pcVar2 = e->to->tuple;
  pcVar3 = e->from->tuple;
  if ((((g_sched_fn_returns_float != 0) && (g_sched_cpu_index != 3)) && (e->latency < 2)) &&
     (((pcVar3 != (c2_tuple *)0x0 && (pcVar3->kind == '\x0e')) &&
      ((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0)))) {
    for (pcVar4 = pcVar2->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
      if ((pcVar4->kind == '\x02') &&
         (((uVar1 = pcVar4->sym->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
          ((uVar1 == '\x05' || (uVar1 == '\x06')))))) goto LAB_1073b1f5;
    }
    pcVar4 = pcVar2->dst;
    if (pcVar4 != (c2_operand *)0x0) {
      while ((pcVar4->kind != '\x02' ||
             ((((uVar1 = pcVar4->sym->cls, uVar1 != '\x03' && (uVar1 != '\x04')) &&
               (uVar1 != '\x05')) && (uVar1 != '\x06'))))) {
        pcVar4 = pcVar4->next;
        if (pcVar4 == (c2_operand *)0x0) {
          return;
        }
      }
LAB_1073b1f5:
      e->latency = 2;
    }
  }
  return;
}

