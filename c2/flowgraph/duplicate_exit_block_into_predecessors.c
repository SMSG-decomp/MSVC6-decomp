void __fastcall duplicate_exit_block_into_predecessors(c2_function *fn)

{
  uint8_t uVar1;
  c2_block *succ;
  c2_tuple *orig;
  c2_tuple *pcVar2;
  c2_tuple *first;
  c2_block *pred;
  int iVar3;
  c2_edge *pcVar4;
  int local_c;
  
  if (g_opt_favor_speed != 0) {
    succ = fn->cfg->last->prev;
    orig = tuple_next_real_in_block(succ->head);
    if (((orig != (c2_tuple *)0x0) && (orig->kind == '\x1a')) &&
       (pcVar2 = tuple_prev_real_in_block(succ->end), (1 << (pcVar2->kind & 0x1f) & 0xa0000U) == 0))
    {
      uVar1 = orig->kind;
      while (uVar1 == '\x1a') {
        orig = orig->next;
        uVar1 = orig->kind;
      }
      pcVar2 = tuple_next_real_before_boundary(orig->prev);
      if (pcVar2 != (c2_tuple *)0x0) {
        iVar3 = 0;
        uVar1 = orig->kind;
        pcVar2 = orig;
        while (uVar1 != '\x19') {
          if (uVar1 == '\x0e') {
            return;
          }
          if (uVar1 == '\x15') {
            return;
          }
          if (((pcVar2->flags & 1) != 0) && (pcVar2->op != 0x19e)) {
            iVar3 = iVar3 + 1;
          }
          pcVar2 = pcVar2->next;
          uVar1 = pcVar2->kind;
        }
        if (iVar3 <= (int)((g_opt_favor_speed != 0) + 1)) {
          pcVar4 = succ->preds;
          local_c = 0;
          for (; pcVar4 != (c2_edge *)0x0; pcVar4 = pcVar4->next_pred) {
            pcVar2 = tuple_prev_real_in_block(pcVar4->from->end);
            if ((pcVar2->flags & 8) != 0) {
              return;
            }
            if (pcVar2->kind == '\x13') {
              return;
            }
            local_c = local_c + 1;
            pcVar4->from->flags = pcVar4->from->flags & 0xfffffffe;
          }
          if (g_opt_favor_speed == 0) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\fg.c",0x1d2d);
          }
          if (local_c * iVar3 < 9) {
            orig->prev->next = succ->end;
            succ->end->prev->next = (c2_tuple *)0x0;
            succ->end->prev = orig->prev;
            orig->prev = (c2_tuple *)0x0;
            while (pcVar4 = succ->preds, pcVar4 != (c2_edge *)0x0) {
              while ((pcVar4->from->flags & 1) != 0) {
                pcVar4 = pcVar4->next_pred;
                if (pcVar4 == (c2_edge *)0x0) {
                  return;
                }
              }
              if (pcVar4 == (c2_edge *)0x0) {
                return;
              }
              pred = pcVar4->from;
              pcVar2 = tuple_prev_real_in_block(pred->end);
              if (pred == succ->prev) {
                if ((pcVar2->kind == '\x11') &&
                   (((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar2->op == 0x18b)))) {
                  pred = split_edge_with_new_block(fn,pcVar4,pred,succ);
                }
                pcVar2 = pred->end->prev;
              }
              else if (((pcVar2->kind == '\x11') &&
                       ((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0)) && (pcVar2->op != 0x18b))
              {
                pcVar2 = pcVar2->prev;
              }
              else {
                pred = split_exit_edge_block(fn,pcVar4,pred,succ);
                pcVar2 = pred->head->next;
                if (pcVar2->kind != '\x1a') {
                  pcVar2 = pcVar2->prev;
                }
              }
              local_c = local_c + -1;
              first = orig;
              if (local_c != 0) {
                first = clone_tuple_list(orig);
              }
              tuple_splice_after(pcVar2,first);
              pred->flags = pred->flags | 1;
            }
          }
        }
      }
    }
  }
  return;
}

