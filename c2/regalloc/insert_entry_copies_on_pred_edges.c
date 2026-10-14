void __fastcall insert_entry_copies_on_pred_edges(c2_function *fn,c2_block *b,int mode)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  int16_t iVar3;
  c2_edge *pcVar4;
  c2_block *pred;
  c2_loop *pcVar5;
  c2_tuple *t;
  c2_symbol *sym;
  c2_bitset *dst;
  uint32_t uVar6;
  c2_bitset *pcVar7;
  c2_bitset *pcVar8;
  int iVar9;
  c2_live_range *home;
  c2_tuple *pcVar10;
  c2_fe_symbol *label_sym;
  c2_block *to;
  c2_block *block2;
  c2_edge *local_14;
  c2_tuple *local_c;
  
  local_14 = b->preds;
  if ((local_14 != (c2_edge *)0x0) && (local_14->next_pred != (c2_edge *)0x0)) {
    to = (c2_block *)0x0;
    dst = bitset_new(6);
    do {
      pcVar4 = local_14->next_pred;
      bitset_copy(dst,b->live_in);
      bitset_andnot(dst,local_14->from->live_out);
      if (dst->chunks != (c2_bitset_chunk *)0x0) {
        pred = local_14->from;
        if ((pred->succs->next_succ != (c2_edge *)0x0) ||
           (block2 = pred, (pred->flags & 0x1000000) != 0)) {
          if (to != (c2_block *)0x0) {
            pcVar8 = bitset_new(6);
            pcVar10 = to->head;
            if (pcVar10 != to->end) {
              do {
                if (pcVar10->op == 0x163) {
                  if (mode == 0) {
                    uVar6 = ((pcVar10->dst->sym->u30).ra)->id;
                  }
                  else {
                    uVar6 = ((pcVar10->dst->u18).reg)->id;
                  }
                  bitset_set(pcVar8,uVar6);
                }
                pcVar10 = pcVar10->next;
              } while (pcVar10 != to->end);
            }
            iVar9 = bitset_equal(dst,pcVar8);
            if (iVar9 != 0) {
              bitset_free(pcVar8);
              pcVar10 = b->head->next;
              uVar2 = pcVar10->kind;
              while (uVar2 == '\x1b') {
                pcVar10 = pcVar10->next;
                uVar2 = pcVar10->kind;
              }
              for (t = pred->end->prev; t != (c2_tuple *)0x0; t = t->prev) {
                if ((1 << (t->kind & 0x1f) & 0xa0000U) == 0) {
                  if (t->kind != 0x1b) break;
                }
                else {
                  local_c = branch_targets_label(t,pcVar10);
                  if (local_c != (c2_tuple *)0x0) break;
                }
              }
              pcVar10 = to->head->next;
              uVar2 = pcVar10->kind;
              while (uVar2 == '\x1b') {
                pcVar10 = pcVar10->next;
                uVar2 = pcVar10->kind;
              }
              if (pcVar10->kind != '\x1a') {
                label_sym = label_symbol_new();
                pcVar10 = label_insert_in_block(label_sym,to);
              }
              tuple_retarget(local_c,(c2_node *)pcVar10,1);
              cfg_edge_redirect(local_14,to,fn);
              goto LAB_10711ab7;
            }
            bitset_free(pcVar8);
          }
          to = split_edge_with_new_block(fn,local_14,pred,b);
          pcVar7 = bitset_clone(b->live_in);
          pcVar8 = pred->live_out;
          to->live_in = pcVar7;
          bitset_and(pcVar7,pcVar8);
          pcVar8 = bitset_clone(pcVar7);
          iVar3 = b->loop_depth;
          pcVar5 = b->loop;
          to->live_out = pcVar8;
          to->loop_depth = iVar3;
          to->loop = pcVar5;
          block2 = to;
          if (mode != 0) {
            pcVar7 = bitset_clone(pcVar7);
            pcVar8 = b->set24;
            to->live = pcVar7;
            pcVar7 = bitset_clone(pcVar8);
            pcVar8 = pred->set28;
            to->set24 = pcVar7;
            bitset_and(pcVar7,pcVar8);
            pcVar8 = bitset_clone(pcVar7);
            to->set28 = pcVar8;
            pcVar8 = bitset_new(6);
            to->set4c = pcVar8;
            bitset_copy(pcVar8,pcVar7);
          }
        }
        uVar6 = bitset_iter_next(dst);
        while (uVar6 != 0xffffffff) {
          if (mode == 0) {
            pcVar10 = find_block_exit_insert_point(block2,g_candidate_symbols[uVar6],fn);
            pcVar10 = insert_live_range_reload
                                (g_candidate_symbols[uVar6],&g_register_candidate_home,pcVar10);
            puVar1 = &pcVar10->dst->flags11;
            *puVar1 = *puVar1 | 0x80;
          }
          else {
            home = live_range_from_id(uVar6);
            sym = home->sym;
            pcVar10 = find_block_exit_insert_point(block2,sym,fn);
            pcVar10 = insert_live_range_reload(sym,home,pcVar10);
            if ((pcVar10->type & 0xfff) == 1) {
              home->flags5 = home->flags5 | 0x80;
            }
            puVar1 = &pcVar10->dst->flags11;
            *puVar1 = *puVar1 | 0x80;
          }
          uVar6 = bitset_iter_next((c2_bitset *)0x0);
        }
        bitset_or(block2->live_out,dst);
        if (mode != 0) {
          bitset_or(block2->live,dst);
        }
      }
LAB_10711ab7:
      local_14 = pcVar4;
    } while (pcVar4 != (c2_edge *)0x0);
    bitset_free(dst);
  }
  return;
}

