void __fastcall sched_dynamic_priority(c2_sched_node *ready_head,uint32_t cycle)

{
  c2_sched_node **ppcVar1;
  c2_sched_edge *pcVar2;
  int32_t *piVar3;
  uint32_t uVar4;
  int iVar5;
  c2_sched_node *pcVar6;
  c2_sched_node *first;
  
  if (((ready_head != (c2_sched_node *)0x0) && (ready_head->ready_next != (c2_sched_node *)0x0)) &&
     ((g_sched_fp_mode != 0 || (-1 < g_sched_weights[4])))) {
    if (g_sched_cpu_index == 3) {
      if (g_sched_fp_mode == 0) {
        return;
      }
    }
    else {
      first = ready_head;
      if (g_sched_fp_mode == 0) {
LAB_1077a296:
        if ((first->tuple != (c2_tuple *)0x0) &&
           (first->priority = first->priority_static, pcVar6 = ready_head,
           (uint)first->earliest <= cycle)) {
          do {
            if ((pcVar6->tuple != (c2_tuple *)0x0) &&
               ((((uint)pcVar6->earliest <= cycle && (first != pcVar6)) &&
                (iVar5 = sched_can_pair_uv(first,pcVar6), iVar5 != 0)))) goto LAB_1077a339;
            ppcVar1 = &pcVar6->ready_next;
            pcVar6 = *ppcVar1;
          } while (*ppcVar1 != (c2_sched_node *)0x0);
          for (pcVar2 = first->succs; pcVar2 != (c2_sched_edge *)0x0; pcVar2 = pcVar2->next_succ) {
            pcVar6 = pcVar2->to;
            if (((pcVar6->npred == 1) && (pcVar2->latency == 0)) &&
               (((uint)pcVar6->earliest <= cycle &&
                (iVar5 = sched_can_pair_uv(first,pcVar6), iVar5 != 0)))) goto LAB_1077a339;
          }
        }
        goto LAB_1077a2fe;
      }
    }
    if ((int)g_sched_fp_peak_depth + (int)g_sched_fp_depth < 8) {
      if (ready_head->priority != 0) {
        return;
      }
    }
    else if (ready_head->priority != 0) {
      do {
        if (ready_head->tuple != (c2_tuple *)0x0) {
          ready_head->priority = 0;
          ready_head->earliest = cycle;
        }
        ready_head = ready_head->ready_next;
      } while (ready_head != (c2_sched_node *)0x0);
      iVar5 = (int)g_sched_unit_count;
      if (iVar5 < 1) {
        return;
      }
      piVar3 = &g_sched_units[0].busy;
      do {
        *piVar3 = 0;
        piVar3 = piVar3 + 3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return;
    }
    if (g_sched_fp_depth + 2 < 8) {
      do {
        if (ready_head->tuple != (c2_tuple *)0x0) {
          ready_head->priority = ready_head->priority_static;
        }
        ready_head = ready_head->ready_next;
      } while (ready_head != (c2_sched_node *)0x0);
      return;
    }
  }
  return;
LAB_1077a339:
  uVar4 = shift_signed(1,(int)g_sched_weights[4]);
  first->priority = uVar4 + first->priority_static;
LAB_1077a2fe:
  ppcVar1 = &first->ready_next;
  first = *ppcVar1;
  if (*ppcVar1 == (c2_sched_node *)0x0) {
    return;
  }
  goto LAB_1077a296;
}

