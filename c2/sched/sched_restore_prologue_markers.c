void __fastcall sched_restore_prologue_markers(c2_function *fn)

{
  c2_cfg *pcVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  int iVar4;
  c2_tuple *aux_marker;
  c2_tuple **slot;
  c2_tuple *pcVar5;
  
  pcVar1 = fn->cfg;
  iVar4 = 0;
  aux_marker = (c2_tuple *)0x0;
  pcVar3 = pcVar1->first->head->next;
  uVar2 = pcVar3->op;
  pcVar5 = pcVar3;
  while (uVar2 != 0x1b4) {
    if (uVar2 == 0x1b6) {
      aux_marker = pcVar5;
    }
    pcVar5 = pcVar5->next;
    uVar2 = pcVar5->op;
  }
  if (pcVar3 != g_sched_prologue_marker_anchor) {
    do {
      pcVar3 = pcVar3->next;
      iVar4 = iVar4 + 1;
    } while (pcVar3 != g_sched_prologue_marker_anchor);
    if (0x27 < iVar4) {
      if (aux_marker == (c2_tuple *)0x0) {
        pcVar3 = pcVar5->prev;
      }
      else {
        pcVar3 = aux_marker->prev;
      }
      iVar4 = 0;
      if (0 < g_sched_released_prologue_count) {
        slot = g_sched_released_prologue;
        do {
          tuple_unlink(*slot);
          tuple_insert_after(pcVar3,*slot);
          iVar4 = iVar4 + 1;
          slot = slot + 1;
        } while (iVar4 < g_sched_released_prologue_count);
      }
      goto LAB_1073f4a9;
    }
  }
  tuple_unlink(pcVar5);
  tuple_insert_after(g_sched_prologue_marker_anchor,pcVar5);
  if (aux_marker != (c2_tuple *)0x0) {
    tuple_unlink(aux_marker);
    tuple_insert_after(g_sched_prologue_marker_anchor,aux_marker);
  }
LAB_1073f4a9:
  pcVar5 = (c2_tuple *)0x0;
  pcVar3 = pcVar1->last->end->prev;
  uVar2 = pcVar3->op;
  while (uVar2 != 0x1b5) {
    if (uVar2 == 0x1b7) {
      pcVar5 = pcVar3;
    }
    pcVar3 = pcVar3->prev;
    uVar2 = pcVar3->op;
  }
  tuple_unlink(pcVar3);
  tuple_insert_before(g_sched_epilogue_marker_anchor,pcVar3);
  if (pcVar5 != (c2_tuple *)0x0) {
    tuple_unlink(pcVar5);
    tuple_insert_before(g_sched_epilogue_marker_anchor,pcVar5);
  }
  return;
}

