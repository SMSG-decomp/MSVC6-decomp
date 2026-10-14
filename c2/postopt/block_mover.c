void __fastcall block_mover(c2_function *fn)

{
  uint8_t uVar1;
  uint32_t uVar2;
  c2_tuple *first;
  c2_tuple *last;
  c2_tuple *pcVar3;
  uint uVar4;
  bool bVar5;
  c2_tuple *pcVar6;
  c2_tuple *pcVar7;
  int iVar8;
  c2_tuple *pcVar9;
  c2_tuple *pcVar10;
  int iVar11;
  c2_tuple *local_10;
  c2_tuple *local_c;
  c2_function *local_8;
  c2_tuple *local_4;
  
  pcVar10 = fn->cfg->last->end;
  pcVar7 = fn->cfg->first->head->next;
  local_8 = fn;
joined_r0x10738bbc:
  pcVar3 = pcVar7;
  if (pcVar3 != pcVar10) {
    local_10 = pcVar3->next;
    pcVar7 = local_10;
    if ((((((pcVar3->kind == '\x11') && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
          (pcVar3->op != 0x18b)) &&
         ((pcVar3->src->kind == '\x04' &&
          (pcVar9 = *(c2_tuple **)&(pcVar3->src->sym->u30).globopt.marks, pcVar9 != (c2_tuple *)0x0)
          ))) && ((pcVar3->flags & 8) == 0)) && (first = pcVar3->next, first->kind == '\x1a')) {
      last = pcVar9->prev;
      if (((((last->kind == '\x11') && ((last->u20).cond_cells == (c2_cond_cell *)0x0)) &&
           (last->op != 0x18b)) || (last->kind == '\x0f')) && (pcVar6 = first, first != pcVar9)) {
        for (; pcVar6 != (c2_tuple *)0x0; pcVar6 = pcVar6->next) {
          if (pcVar6 == pcVar9) {
            if (pcVar6 != (c2_tuple *)0x0) {
              for (pcVar7 = pcVar9->next;
                  (((pcVar7->kind != '\x11' || ((pcVar7->u20).cond_cells != (c2_cond_cell *)0x0)) ||
                   (pcVar7->op == 0x18b)) && (pcVar7->kind != '\x0f')); pcVar7 = pcVar7->next) {
              }
              if (pcVar7 == (c2_tuple *)0x0) {
                pcVar7 = local_8->cfg->last->end->prev->prev;
              }
              tuple_move_range(pcVar7->next,first,last);
              tuple_unlink_free(pcVar3);
              pcVar7 = local_10;
            }
            break;
          }
        }
      }
    }
    goto joined_r0x10738bbc;
  }
  local_4 = local_8->cfg->last->end;
  local_c = local_8->cfg->first->head->next;
  pcVar10 = local_c;
  if (local_c != local_4) {
    do {
      local_10 = pcVar10->next;
      pcVar7 = local_10;
      if ((((pcVar10->kind != '\x11') || ((pcVar10->u20).cond_cells != (c2_cond_cell *)0x0)) ||
          ((pcVar10->op == 0x18b ||
           ((pcVar10->src->kind != '\x04' || (*(int *)((int)&pcVar10->src->sym->u30 + 2) == 0))))))
         || ((pcVar10->flags & 8) != 0)) goto LAB_10738c06;
      local_c = pcVar10;
      iVar8 = delete_jump_to_next(pcVar10,&local_10);
      if (iVar8 == 0) {
        bVar5 = false;
        pcVar7 = *(c2_tuple **)&(pcVar10->src->sym->u30).globopt.marks;
        for (pcVar3 = pcVar7->next; pcVar3 != (c2_tuple *)0x0; pcVar3 = pcVar3->next) {
          uVar4 = pcVar3->op;
          if (uVar4 != 0x162) {
            if (((pcVar3->flags & 1) != 0) && ((uVar4 == 0 || (0x143 < uVar4)))) break;
            switch(pcVar3->kind) {
            case '\x0f':
            case '\x11':
            case '\x13':
            case '\x18':
              goto switchD_10738e1c_caseD_f;
            case '\x1a':
              bVar5 = true;
            }
          }
        }
switchD_10738e1c_caseD_f:
        uVar1 = pcVar3->kind;
        if ((uVar1 == '\x18') ||
           ((((uVar4 = pcVar3->op, uVar4 != 0x162 && ((pcVar3->flags & 1) != 0)) &&
             ((uVar4 == 0 || (0x143 < uVar4)))) ||
            (((uVar1 == '\x13' || (pcVar3 == pcVar10)) ||
             ((uVar1 == '\x11' &&
              ((((((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0 || (uVar4 == 0x18b)) ||
                 (pcVar3->src->kind != '\x04')) || (*(int *)((int)&pcVar3->src->sym->u30 + 2) == 0))
               || ((((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0 && (uVar4 != 0x18b)) &&
                   ((pcVar3->src->kind == '\x04' &&
                    ((pcVar9 = *(c2_tuple **)((int)&pcVar3->src->sym->u30 + 2),
                     pcVar9 != (c2_tuple *)0x0 && (pcVar9 == pcVar7))))))))))))))))
        goto LAB_10738e0b;
        pcVar9 = tuple_prev_real_in_block(pcVar7);
        if (((bVar5) ||
            (((pcVar9->kind != '\x11' || ((pcVar9->u20).cond_cells != (c2_cond_cell *)0x0)) ||
             (pcVar9->op == 0x18b)))) ||
           (((pcVar9->src->kind == '\x04' &&
             (pcVar9 = *(c2_tuple **)((int)&pcVar9->src->sym->u30 + 2), pcVar9 != (c2_tuple *)0x0))
            && (pcVar9 == pcVar7)))) {
          iVar11 = 0;
          pcVar10 = pcVar7->next;
          iVar8 = g_opt_favor_speed;
          do {
            if ((pcVar10->flags & 1) != 0) {
              iVar8 = tuple_encoded_length(pcVar10);
              iVar11 = iVar11 + iVar8;
              iVar8 = g_opt_favor_speed;
            }
          } while ((pcVar10 != pcVar3) &&
                  (pcVar10 = pcVar10->next, iVar11 <= (int)((-(uint)(iVar8 != 0) & 0x12) + 2)));
          if (iVar11 <= (int)((-(uint)(iVar8 != 0) & 0x12) + 2)) {
            pcVar10 = pcVar7->next;
            pcVar7 = local_c;
            while( true ) {
              for (; pcVar10->kind == '\x1a'; pcVar10 = pcVar10->next) {
                if (pcVar10 == pcVar3) goto LAB_10738fab;
              }
              pcVar9 = (c2_tuple *)node_clone((c2_node *)pcVar10);
              tuple_insert_after(pcVar7,pcVar9);
              if (((pcVar9->kind == '\x11') && (pcVar9->src->kind == '\x04')) &&
                 (pcVar7 = *(c2_tuple **)((int)&pcVar9->src->sym->u30 + 2),
                 pcVar7 != (c2_tuple *)0x0)) {
                label_add_ref(pcVar7,(c2_node *)pcVar9);
              }
              pcVar7 = pcVar9;
              if (pcVar10 == pcVar3) break;
              pcVar10 = pcVar10->next;
            }
LAB_10738fab:
            pcVar10 = local_c->prev;
            tuple_unlink_free(local_c);
            if (pcVar10->kind == '\x0e') {
              convert_tail_call_to_jmp(pcVar10);
            }
            if (((pcVar7->kind == '\x11') && ((pcVar7->u20).cond_cells == (c2_cond_cell *)0x0)) &&
               (pcVar7->op != 0x18b)) goto LAB_10738c06;
          }
          goto LAB_10738e0b;
        }
        pcVar7->prev->next = pcVar3->next;
        pcVar3->next->prev = pcVar7->prev;
        pcVar3->next = (c2_tuple *)0x0;
        tuple_splice_after(pcVar10,pcVar7);
        tuple_unlink_free(pcVar10);
        pcVar7 = pcVar3;
      }
      else {
LAB_10738e0b:
        pcVar7 = local_10;
      }
LAB_10738c06:
      local_10 = pcVar7;
      pcVar10 = local_10;
      local_c = local_10;
    } while (local_10 != local_4);
  }
  pcVar10 = local_8->cfg->last->end;
  uVar1 = pcVar10->kind;
  while (uVar1 != '\x16') {
    pcVar10 = pcVar10->prev;
    uVar1 = pcVar10->kind;
  }
  uVar1 = pcVar10->kind;
  while (uVar1 == '\x16') {
    pcVar10 = pcVar10->prev;
    uVar1 = pcVar10->kind;
  }
  if ((pcVar10->kind == '\x1a') && (*(int *)&pcVar10->src[1].type == 0)) {
    pcVar10 = pcVar10->prev;
  }
  uVar2 = pcVar10->op;
  while (uVar2 == 0xb9) {
    pcVar10 = pcVar10->prev;
    uVar2 = pcVar10->op;
  }
  if (pcVar10->kind == '\x0e') {
    convert_tail_call_to_jmp(pcVar10);
  }
  return;
}

