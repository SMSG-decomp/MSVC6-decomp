void __fastcall sched_mark_branch_feeders(c2_sched_node *entry,c2_sched_node *exit)

{
  uint8_t *puVar1;
  byte bVar2;
  c2_tuple *pcVar3;
  uint uVar4;
  c2_sched_edge *pcVar5;
  c2_sched_node *pcVar6;
  c2_operand *pcVar7;
  c2_operand *pcVar8;
  
  pcVar3 = exit->prev->tuple;
  uVar4 = pcVar3->op;
  if (uVar4 < 0x114) {
    if (((uVar4 != 0x113) && (uVar4 != 0xf)) && (uVar4 != 0x16)) {
      return;
    }
  }
  else if (uVar4 != 0x11b) {
    return;
  }
  pcVar5 = exit->prev->preds;
  do {
    if (pcVar5 == (c2_sched_edge *)0x0) {
      return;
    }
    uVar4 = pcVar5->type;
    if ((uVar4 & 1) == 0) {
      if ((uVar4 & 0x80000) != 0) {
        pcVar6 = pcVar5->from;
        if ((pcVar6->tuple->flags & 1) != 0) {
          pcVar8 = pcVar6->tuple->dst;
          pcVar7 = pcVar3->src->next;
          if (pcVar8 != (c2_operand *)0x0) {
            do {
              if ((((pcVar7->kind == '\x01') && (pcVar8->kind == '\x01')) &&
                  (((pcVar7->u18).reg)->storage == ((pcVar8->u18).reg)->storage)) ||
                 (((pcVar7->kind == '\x02' && (pcVar8->kind == '\x02')) &&
                  (pcVar7->sym->storage == pcVar8->sym->storage)))) {
                bVar2 = pcVar6->pipe;
                pcVar5->latency = 1;
                pcVar6->pipe = bVar2 | 0x80;
                pcVar5->type = uVar4 | 1;
                break;
              }
              pcVar8 = pcVar8->next;
            } while (pcVar8 != (c2_operand *)0x0);
          }
        }
      }
    }
    else {
      puVar1 = &pcVar5->from->pipe;
      *puVar1 = *puVar1 | 0x80;
    }
    pcVar5 = pcVar5->next_pred;
  } while( true );
}

