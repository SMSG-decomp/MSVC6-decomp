void __fastcall replace_iv_with_final_value(c2_loop *loop,c2_function *fn)

{
  uint16_t uVar1;
  c2_list_cell *pcVar2;
  c2_list_cell *list;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  bool bVar5;
  uint32_t uVar6;
  c2_symbol *s;
  int iVar7;
  c2_operand *pcVar8;
  c2_tuple *pcVar9;
  c2_tuple *pcVar10;
  c2_operand *pcVar11;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  if (loop->trip_count != (c2_operand *)0x0) {
    reset_iv_worklists();
    set_preheader_insert_point(loop);
    bVar5 = false;
    uVar6 = bitset_iter_next(g_iv_syms);
    while (uVar6 != 0xffffffff) {
      s = symbol_by_id(uVar6);
      pcVar2 = s->defs;
      if (((pcVar2 != (c2_list_cell *)0x0) && (pcVar2->next == (c2_list_cell *)0x0)) &&
         (list = s->uses, list != (c2_list_cell *)0x0)) {
        if (list->next == (c2_list_cell *)0x0) {
          pcVar3 = (list->u04).tuple;
          pcVar10 = (pcVar2->u04).tuple;
          if ((((pcVar3->flags13 == '\x04') && (pcVar10->flags13 == '\x04')) &&
              ((pcVar3->op == 0x16d &&
               ((pcVar10->op == 0x15b && (iVar7 = operand_live_after_loop(pcVar10->dst), iVar7 != 0)
                ))))) && (uVar6 = block_range_dominated(pcVar10,loop->exit_compare), uVar6 != 0)) {
            uVar1 = pcVar10->type;
            pcVar4 = pcVar10->dst;
            pcVar11 = pcVar3->src->next;
            operand_retype_keep_sets(pcVar11,uVar1);
            insert_fn_00 = tuple_insert_before;
            pcVar9 = g_preheader_insert_point;
            pcVar8 = trip_count_as_type(loop,uVar1,fn);
            pcVar9 = tuple_new_binary_temp(0x16f,uVar1,pcVar8,pcVar11,insert_fn_00,pcVar9);
            pcVar9 = tuple_new_binary_temp
                               (pcVar3->op,uVar1,pcVar4,pcVar9->dst,tuple_insert_before,
                                g_preheader_insert_point);
            tuple_new(pcVar10->op,uVar1,pcVar4,pcVar9->dst,tuple_insert_before,
                      g_preheader_insert_point);
            bVar5 = true;
            symbol_remove_def(s,pcVar10);
            symbol_remove_use(s,pcVar3);
            iv_pending_free_add_unique(pcVar3);
            iv_pending_free_add_unique(pcVar10);
          }
        }
        else if ((((list != (c2_list_cell *)0x0) && (list->next != (c2_list_cell *)0x0)) &&
                 (list->next->next == (c2_list_cell *)0x0)) &&
                (iVar7 = list_contains_value(list,(int)loop->exit_compare), iVar7 != 0)) {
          pcVar3 = (s->defs->u04).tuple;
          pcVar10 = (s->uses->u04).tuple;
          if (pcVar10 == loop->exit_compare) {
            pcVar10 = (s->uses->next->u04).tuple;
          }
          if (((pcVar10->flags13 == '\x04') && (pcVar3->flags13 == '\x04')) &&
             (((pcVar10->op == 0x16d &&
               ((pcVar3->op == 0x15b && (iVar7 = operand_live_after_loop(pcVar3->dst), iVar7 != 0)))
               ) && (uVar6 = block_range_dominated(pcVar3,loop->exit_compare), uVar6 != 0)))) {
            uVar1 = pcVar3->type;
            pcVar4 = pcVar3->dst;
            pcVar11 = pcVar10->src->next;
            operand_retype_keep_sets(pcVar11,uVar1);
            insert_fn = tuple_insert_before;
            pcVar9 = g_preheader_insert_point;
            pcVar8 = trip_count_as_type(loop,uVar1,fn);
            pcVar9 = tuple_new_binary_temp(0x16f,uVar1,pcVar8,pcVar11,insert_fn,pcVar9);
            pcVar10 = tuple_new_binary_temp
                                (pcVar10->op,uVar1,pcVar4,pcVar9->dst,tuple_insert_before,
                                 g_preheader_insert_point);
            bVar5 = true;
            g_countdown_test_tuple =
                 tuple_new(pcVar3->op,uVar1,pcVar4,pcVar10->dst,tuple_insert_before,
                           g_preheader_insert_point);
          }
        }
      }
      uVar6 = bitset_iter_next((c2_bitset *)0x0);
    }
    free_pending_iv_tuples();
    if (bVar5) {
      cleanup_preheader_after_sr(loop,fn);
    }
  }
  return;
}

