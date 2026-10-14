void __fastcall delete_empty_loop(c2_loop *loop,c2_function *fn)

{
  uint8_t uVar1;
  c2_operand *opnd;
  c2_symbol *s;
  c2_operand *pcVar2;
  c2_block *pcVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_edge *edge;
  int iVar7;
  c2_operand *local_14;
  c2_block *local_10;
  c2_block *local_c;
  c2_block *local_8;
  c2_function *local_4;
  
  local_10 = loop->first;
  local_c = loop->last;
  if (g_iv_syms->chunks != (c2_bitset_chunk *)0x0) {
    local_8 = local_10;
    local_4 = fn;
    if (local_10 != local_c->next) {
      do {
        pcVar3 = local_10;
        local_14 = (c2_operand *)local_10->head->next;
        if (local_14 != (c2_operand *)local_10->end) {
          do {
            if ((local_14->flags9 & 1) != 0) {
              uVar1 = *(uint8_t *)((int)&local_14->x12 + 1);
              if ((((uVar1 != '\x04') && (uVar1 != '\x01')) && (uVar1 != '\x02')) &&
                 (uVar1 != '\x11')) goto LAB_1074812f;
              if ((local_14->op == 0x15b) &&
                 (iVar7 = operand_live_after_loop((c2_operand *)local_14->tag), iVar7 != 0)) {
                if (g_countdown_test_tuple == (c2_tuple *)0x0) {
                  return;
                }
                iVar7 = operand_compare(g_countdown_test_tuple->dst,(c2_operand *)local_14->tag);
                if (iVar7 != 0) goto LAB_10748138;
              }
            }
            local_14 = local_14->next;
          } while (local_14 != (c2_operand *)pcVar3->end);
        }
        local_10 = pcVar3->next;
      } while (local_10 != loop->last->next);
    }
LAB_1074812f:
    pcVar2 = local_14;
    if (local_14->op == 0x17d) {
      opnd = (local_14->u18).children;
      pcVar5 = opnd->next;
      uVar4 = is_induction_variable_operand(opnd);
      if (((uVar4 != 0) && (uVar4 = is_loop_invariant_operand(pcVar5), uVar4 != 0)) &&
         (pcVar5 = (c2_operand *)find_next_use_of_dst((c2_tuple *)pcVar2,&local_14),
         pcVar5->kind == '\x11')) {
        local_14 = pcVar2->next;
        uVar1 = *(uint8_t *)((int)&local_14->x12 + 1);
        while ((uVar1 == '\x04' &&
               (iVar7 = operand_live_after_loop((c2_operand *)local_14->tag), iVar7 == 0))) {
          local_14 = local_14->next;
          uVar1 = *(uint8_t *)((int)&local_14->x12 + 1);
        }
        if (((local_14 == pcVar5) &&
            (pcVar6 = tuple_next_real_before_boundary((c2_tuple *)pcVar5), pcVar6 == (c2_tuple *)0x0
            )) && (local_10 == local_c)) {
          edge = flow_edge_find(local_c,local_8);
          cfg_remove_edge(local_4,edge);
          s = opnd->sym;
          symbol_remove_use(s,pcVar2);
          local_14 = (c2_operand *)symbol_pop_use(s);
          tuple_unlink_free((c2_tuple *)local_14);
          local_14 = (c2_operand *)symbol_pop_def(s);
          tuple_unlink_free((c2_tuple *)local_14);
          tuple_unlink_free((c2_tuple *)pcVar2);
          branch_free((c2_tuple *)pcVar5);
          g_flowgraph_dirty = 1;
          recompute_loop_liveness(loop,3);
          if (loop->trip_count != (c2_operand *)0x0) {
            node_free((c2_node *)loop->trip_count);
          }
          loop->trip_count = (c2_operand *)0x0;
          loop->exit_compare = (c2_tuple *)0x0;
          (loop->u30).iv_update_clones = (c2_list_cell *)0x0;
          return;
        }
      }
    }
LAB_10748138:
    if (g_countdown_test_tuple != (c2_tuple *)0x0) {
      pcVar2 = g_countdown_test_tuple->src;
      if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
        tuple_drop_unused_results(pcVar2);
      }
      tuple_unlink_free(g_countdown_test_tuple);
    }
  }
  return;
}

