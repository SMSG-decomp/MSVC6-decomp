void __fastcall sched_release_prologue_epilogue(c2_function *fn)

{
  uint8_t uVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  c2_tuple *pcVar5;
  uint uVar6;
  c2_tuple **slot;
  int iVar7;
  c2_tuple *aux_marker;
  c2_tuple *marker;
  c2_tuple *anchor;
  
  anchor = fn->cfg->first->head;
  uVar1 = anchor->kind;
  while (uVar1 != '\x17') {
    anchor = anchor->next;
    uVar1 = anchor->kind;
  }
  marker = anchor->next;
  uVar4 = function_stores_to_stack_symbol(marker);
  aux_marker = (c2_tuple *)0x0;
  uVar2 = marker->op;
  while (uVar2 != 0x1b4) {
    if (uVar2 < 0x2f) {
      if (uVar2 == 0x2e) {
        if ((((marker->dst->kind == '\x01') && ((marker->dst->u18).reg == g_reg_symbols + 5)) &&
            (pcVar3 = marker->src->next, pcVar3->kind == '\a')) &&
           ((pcVar3->u18).reg == (c2_symbol *)0xfffffff8)) goto LAB_1073a3bd;
      }
      else if (uVar2 == 1) {
        pcVar3 = marker->dst;
        if ((pcVar3->kind == '\x01') &&
           ((((pcVar3->u18).reg == g_reg_symbols + 6 &&
             (((fn->flags & 0x10) == 0 || ((fn->flags & 0x600000) != 0)))) ||
            (((pcVar3->u18).reg == g_reg_symbols + 6 &&
             ((marker->src->kind == '\x01' && ((marker->src->u18).reg == g_reg_symbols + 5))))))))
        goto LAB_1073a3bd;
      }
      else if (uVar2 == 4) {
LAB_1073a3bd:
        anchor = marker;
      }
      else if (uVar2 == 0xd) goto LAB_1073a3ab;
    }
    else if (uVar2 == 0x32) {
      if (((marker->dst->kind == '\x01') && ((marker->dst->u18).reg == g_reg_symbols + 5)) &&
         (((fn->flags & 0x10) == 0 || ((uVar4 != 0 || ((fn->flags & 0x600000) != 0))))))
      goto LAB_1073a3bd;
    }
    else if (uVar2 == 0xba) {
LAB_1073a3ab:
      if ((marker->src->kind == '\x01') && ((marker->src->u18).reg == g_reg_symbols + 2))
      goto LAB_1073a3bd;
    }
    else if (uVar2 == 0x1b6) {
      aux_marker = marker;
    }
    marker = marker->next;
    uVar2 = marker->op;
  }
  if (aux_marker == (c2_tuple *)0x0) {
    pcVar5 = marker->prev;
  }
  else {
    pcVar5 = aux_marker->prev;
  }
  iVar7 = 0;
  g_sched_released_prologue_count = 0;
  g_sched_prologue_marker_anchor = pcVar5;
  if (pcVar5 != anchor) {
    slot = g_sched_released_prologue;
    do {
      if (0x1079924f < (int)slot) break;
      *slot = pcVar5;
      pcVar5 = pcVar5->prev;
      iVar7 = iVar7 + 1;
      slot = slot + 1;
    } while (pcVar5 != anchor);
    g_sched_released_prologue_count = iVar7;
    if (iVar7 == 10) {
      anchor = pcVar5;
    }
  }
  tuple_unlink(marker);
  tuple_insert_after(anchor,marker);
  if (aux_marker != (c2_tuple *)0x0) {
    tuple_unlink(aux_marker);
    tuple_insert_after(anchor,aux_marker);
  }
  anchor = fn->cfg->last->end;
  uVar1 = anchor->kind;
  while (uVar1 != '\x18') {
    anchor = anchor->prev;
    uVar1 = anchor->kind;
  }
  marker = anchor->prev;
  aux_marker = (c2_tuple *)0x0;
  uVar6 = marker->op;
  if (uVar6 != 0x1b5) {
    do {
      if (uVar6 < 0xa8) {
        if (uVar6 == 0xa7) {
LAB_1073a47c:
          anchor = marker;
        }
        else if (uVar6 == 1) {
          if (((marker->src->kind == '\x01') && ((marker->src->u18).reg == g_reg_symbols + 6)) &&
             (((fn->flags & 0x10) == 0 || ((fn->flags & 0x600000) != 0)))) goto LAB_1073a47c;
        }
        else {
          if (uVar6 == 0xc) goto LAB_1073a480;
          if ((uVar6 == 0x2d) &&
             ((marker->dst->kind == '\x01' && ((marker->dst->u18).reg == g_reg_symbols + 5))))
          goto LAB_1073a47c;
        }
      }
      else if (uVar6 == 0xb9) {
LAB_1073a480:
        pcVar3 = marker->dst;
        if (((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == g_reg_symbols + 2)) ||
           ((((fn->flags & 0x10) == 0 || ((fn->flags & 0x600000) != 0)) &&
            ((pcVar3->kind == '\x01' && ((pcVar3->u18).reg == g_reg_symbols + 6))))))
        goto LAB_1073a47c;
      }
      else if (uVar6 == 0x1b7) {
        aux_marker = marker;
      }
      marker = marker->prev;
      uVar6 = marker->op;
    } while (uVar6 != 0x1b5);
    if (aux_marker != (c2_tuple *)0x0) {
      g_sched_epilogue_marker_anchor = aux_marker->next;
      goto LAB_1073a314;
    }
  }
  g_sched_epilogue_marker_anchor = marker->next;
LAB_1073a314:
  tuple_unlink(marker);
  tuple_insert_before(anchor,marker);
  if (aux_marker != (c2_tuple *)0x0) {
    tuple_unlink(aux_marker);
    tuple_insert_before(anchor,aux_marker);
  }
  return;
}

