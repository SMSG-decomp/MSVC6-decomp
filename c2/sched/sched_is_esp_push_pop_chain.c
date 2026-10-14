int __fastcall sched_is_esp_push_pop_chain(c2_symbol *sym,c2_sched_edge *edge)

{
  c2_sched_node *pcVar1;
  c2_sched_node *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  pcVar1 = edge->from;
  pcVar2 = edge->to;
  if ((sym == g_reg_symbols + 5) && (g_sched_cpu_index != 3)) {
    uVar3 = pcVar1->tuple->op;
    if (((uVar3 == 0xd) || (uVar3 == 0xba)) &&
       ((((uVar4 = pcVar2->tuple->op, uVar4 == 0xd || (uVar4 == 0xba)) &&
         ((pcVar1->sflags & 1) == 0)) && ((pcVar2->sflags & 1) == 0)))) {
      return 1;
    }
    if ((((uVar3 == 0xc) || (uVar3 == 0xb9)) &&
        ((uVar3 = pcVar2->tuple->op, uVar3 == 0xc || (uVar3 == 0xb9)))) &&
       (((pcVar1->sflags & 2) == 0 && ((pcVar2->sflags & 2) == 0)))) {
      return 1;
    }
  }
  return 0;
}

