void delete_empty_loop_part
               (c2_loop *loop,uint32_t copy_op,c2_block *block,c2_tuple *cursor,
               c2_block *saved_block,c2_block *last_block,c2_block *first_block,c2_function *fn)

{
  uint8_t uVar1;
  c2_symbol *s;
  uint32_t uVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  c2_edge *edge;
  int iVar4;
  c2_operand *bound_opnd;
  c2_tuple *compare;
  c2_operand *iv_opnd;
  
  while( true ) {
    do {
      cursor = cursor->next;
      if (cursor == block->end) {
        do {
          block = block->next;
          saved_block = block;
          if (block == loop->last->next) goto LAB_1074812f;
          cursor = block->head->next;
        } while (cursor == block->end);
      }
    } while ((cursor->flags & 1) == 0);
    uVar1 = cursor->flags13;
    if ((((uVar1 != '\x04') && (uVar1 != '\x01')) && (uVar1 != '\x02')) && (uVar1 != '\x11')) break;
    if ((cursor->op == copy_op) && (iVar4 = operand_live_after_loop(cursor->dst), iVar4 != 0)) {
      if (g_countdown_test_tuple == (c2_tuple *)0x0) {
        return;
      }
      iVar4 = operand_compare(g_countdown_test_tuple->dst,cursor->dst);
      if (iVar4 != 0) {
LAB_10748138:
        if (g_countdown_test_tuple != (c2_tuple *)0x0) {
          iv_opnd = g_countdown_test_tuple->src;
          if (((1 << (iv_opnd->kind & 0x1f) & 6U) != 0) && (iv_opnd->sym->def != (c2_tuple *)0x0)) {
            tuple_drop_unused_results(iv_opnd);
          }
          tuple_unlink_free(g_countdown_test_tuple);
        }
        return;
      }
    }
  }
LAB_1074812f:
  compare = cursor;
  if (cursor->op == 0x17d) {
    iv_opnd = cursor->src;
    bound_opnd = iv_opnd->next;
    uVar2 = is_induction_variable_operand(iv_opnd);
    if (((uVar2 != 0) && (uVar2 = is_loop_invariant_operand(bound_opnd), uVar2 != 0)) &&
       (t = find_next_use_of_dst(compare,(c2_operand **)&cursor), t->kind == '\x11')) {
      cursor = compare->next;
      uVar1 = cursor->flags13;
      while ((uVar1 == '\x04' && (iVar4 = operand_live_after_loop(cursor->dst), iVar4 == 0))) {
        cursor = cursor->next;
        uVar1 = cursor->flags13;
      }
      if (((cursor == t) && (pcVar3 = tuple_next_real_before_boundary(t), pcVar3 == (c2_tuple *)0x0)
          ) && (saved_block == last_block)) {
        edge = flow_edge_find(last_block,first_block);
        cfg_remove_edge(fn,edge);
        s = iv_opnd->sym;
        symbol_remove_use(s,compare);
        cursor = symbol_pop_use(s);
        tuple_unlink_free(cursor);
        cursor = symbol_pop_def(s);
        tuple_unlink_free(cursor);
        tuple_unlink_free(compare);
        branch_free(t);
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
  goto LAB_10748138;
}

