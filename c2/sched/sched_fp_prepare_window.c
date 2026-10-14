void __fastcall sched_fp_prepare_window(c2_tuple *first,c2_tuple **end)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  c2_tuple *t;
  int16_t iVar5;
  int iVar6;
  int local_8;
  
  sched_fp_reset_stack();
  pcVar1 = *end;
  local_8 = 0;
  iVar5 = g_sched_fp_peak_depth;
  while (g_sched_fp_peak_depth = iVar5, t = first, t != pcVar1) {
    first = t->next;
    iVar5 = g_sched_fp_peak_depth;
    if (((t->flags & 1) != 0) &&
       ((((t->type & 0xf000) == 0x4000 || (t->kind == '\x0e')) || (t->op == 0x5b)))) {
      if (t->op == 0x5f) {
        tuple_unlink(t);
        node_free((c2_node *)t);
        iVar5 = g_sched_fp_peak_depth;
      }
      else {
        for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if (((pcVar2->kind == '\x01') && (pcVar3 = pcVar2->sym, pcVar3->cls == '\x03')) &&
             ((pcVar3->def != (c2_tuple *)0x0 &&
              ((((pcVar2->u18).reg)->cls == '\x01' && ((pcVar2->type & 0xf000) == 0x4000)))))) {
            uVar4 = ((pcVar2->u18).reg)->id;
            (pcVar2->u18).reg = pcVar3;
            pcVar2->rank = uVar4 - 0x1f;
          }
        }
        for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if ((((pcVar2->kind == '\x01') && (pcVar3 = pcVar2->sym, pcVar3->cls == '\x03')) &&
              (pcVar3->def != (c2_tuple *)0x0)) &&
             ((((pcVar2->u18).reg)->cls == '\x01' && ((pcVar2->type & 0xf000) == 0x4000)))) {
            uVar4 = ((pcVar2->u18).reg)->id;
            (pcVar2->u18).reg = pcVar3;
            pcVar2->rank = uVar4 - 0x1f;
          }
        }
        iVar6 = x87_stack_effect(t);
        local_8 = local_8 + iVar6;
        iVar5 = (int16_t)local_8;
        if (local_8 <= g_sched_fp_peak_depth) {
          iVar5 = g_sched_fp_peak_depth;
        }
      }
    }
  }
  g_sched_fp_depth = 8 - (short)_g_sched_fp_tos;
  return;
}

