void __fastcall strength_reduce_loop(int loop,c2_function *fn,c2_operand *op3)

{
  ushort uVar1;
  uint16_t uVar2;
  c2_symbol *pcVar3;
  c2_symbol *pcVar4;
  c2_cse_expr *pcVar5;
  c2_tuple *pcVar6;
  c2_list_cell *pcVar7;
  c2_operand *pcVar8;
  c2_tuple *pcVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  c2_operand *pcVar12;
  c2_operand *pcVar13;
  int iVar14;
  uint32_t uVar15;
  c2_tuple *local_28;
  c2_tuple *local_24;
  int local_8;
  
  set_preheader_insert_point((c2_loop *)loop);
  pcVar6 = tuple_next_real(*(c2_tuple **)(*(int *)(loop + 0xc) + 0x1c));
  uVar1 = pcVar6->line;
  if (op3 != (c2_operand *)0x0) {
    recse_loop_after_strength_reduction((c2_loop *)loop,fn);
    recompute_loop_liveness((c2_loop *)loop,0);
    find_basic_induction_variables((c2_loop *)loop);
    build_iv_def_use_lists((c2_loop *)loop);
  }
  local_8 = 0;
  do {
    reset_iv_worklists();
    pcVar7 = collect_iv_candidates((c2_loop *)loop,1);
    if (pcVar7 == (c2_list_cell *)0x0) break;
    pcVar6 = iv_worklist_pop();
    while (pcVar3 = g_derived_iv_head, pcVar6 != (c2_tuple *)0x0) {
      if (pcVar6->line != 0) {
        g_current_line_abs = fn->line_base + (uint)pcVar6->line;
        g_cur_line = pcVar6->line;
      }
      uVar2 = pcVar6->type;
      pcVar8 = get_derived_iv(uVar2,pcVar6->op,pcVar6->src,pcVar6->src->next);
      pcVar3 = pcVar8->sym;
      pcVar4 = pcVar6->dst->sym;
      pcVar9 = tuple_new(0x15b,uVar2,pcVar6->dst,pcVar8,tuple_insert_after,pcVar6);
      enter_tuple_in_expression_table(pcVar9,0);
      add_symbol_loop_use(pcVar3,pcVar9);
      uVar11 = pcVar4->id;
      uVar10 = bitset_test(g_hoisted_exprs,uVar11);
      if ((uVar10 != 0) && (uVar11 = sparse_set_test_and_add(g_sr_seen_exprs,uVar11), uVar11 == 0))
      {
        bitset_set(g_sr_init_exprs,((pcVar9->u14).expr)->id);
      }
      sr_queue_dead_iv_tuples(pcVar6->dst,pcVar6);
      pcVar6 = iv_worklist_pop();
    }
    for (; pcVar3 != (c2_symbol *)0xffffffff; pcVar3 = pcVar3->order_next) {
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      pcVar5 = (pcVar3->u18).expr;
      uVar2 = pcVar5->type;
      uVar11 = map_iv_update_opcode(pcVar5->op);
      uVar10 = is_induction_variable_operand(pcVar5->operands);
      if (((uVar10 == 0) && (uVar11 != 0x16e)) && (uVar11 != 0x15f)) {
        op3 = pcVar5->operands;
        pcVar8 = op3->next;
      }
      else {
        pcVar8 = pcVar5->operands;
        op3 = pcVar8->next;
      }
      pcVar12 = materialize_value_in_preheader(uVar2,pcVar8,g_preheader_insert_point,0);
      if (uVar11 == 0x15f) {
        local_24 = tuple_new_unary_temp
                             (0x15f,uVar2,pcVar12,tuple_insert_before,g_preheader_insert_point);
      }
      else {
        pcVar13 = materialize_value_in_preheader(uVar2,op3,g_preheader_insert_point,0);
        local_24 = tuple_new_binary_temp
                             (uVar11,uVar2,pcVar12,pcVar13,tuple_insert_before,
                              g_preheader_insert_point);
      }
      pcVar12 = operand_new_sym(0x14a,uVar2,pcVar3);
      tuple_new(0x15b,uVar2,pcVar12,local_24->dst,tuple_insert_before,g_preheader_insert_point);
      if (pcVar8->kind == '\x02') {
        for (pcVar7 = pcVar8->sym->defs; pcVar7 != (c2_list_cell *)0x0; pcVar7 = pcVar7->next) {
          pcVar6 = (pcVar7->u04).tuple;
          local_28 = pcVar6;
          if (((pcVar6->op == 0x16d) || (pcVar6->op == 0x16e)) &&
             ((pcVar6->next->op == 0x15b &&
              ((iVar14 = operand_compare(pcVar6->dst,pcVar6->next->src), iVar14 == 0 &&
               (iVar14 = operand_compare(pcVar6->next->dst,pcVar6->src), iVar14 == 0)))))) {
            local_28 = pcVar6->next;
          }
          if (local_28->line != 0) {
            g_current_line_abs = fn->line_base + (uint)local_28->line;
            g_cur_line = local_28->line;
          }
          uVar10 = pcVar6->op;
          if (uVar10 == 0x15b) {
            pcVar8 = pcVar6->src;
            if (((1 << (pcVar8->kind & 0x1f) & 6U) == 0) ||
               (pcVar5 = (pcVar8->sym->u18).expr, pcVar5 == (c2_cse_expr *)0x0)) {
              if (((1 << (pcVar6->src->kind & 0x1f) & 6U) == 0) ||
                 (pcVar9 = pcVar6->src->sym->def, pcVar9 == (c2_tuple *)0x0)) goto LAB_10746e17;
              uVar10 = pcVar9->op;
              pcVar13 = pcVar9->src;
              pcVar8 = pcVar13->next;
            }
            else {
              uVar10 = pcVar5->op;
              switch(uVar10) {
              case 0x16d:
              case 0x16e:
                break;
              default:
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0xce9);
              case 0x179:
              case 0x17a:
                uVar10 = map_iv_update_opcode(uVar10);
                break;
              case 0x17b:
              case 0x17c:
                goto LAB_10746e5e;
              }
              uVar15 = is_induction_variable_operand(pcVar5->operands);
              if ((uVar15 == 0) && (uVar10 != 0x16e)) {
                pcVar8 = pcVar5->operands;
LAB_10746e9b:
                pcVar13 = pcVar8->next;
              }
              else {
                pcVar13 = pcVar5->operands;
                pcVar8 = pcVar13->next;
              }
            }
LAB_10746cea:
            pcVar13 = get_derived_iv(uVar2,uVar11,pcVar13,op3);
            if (uVar11 == 0x16f) {
              pcVar8 = get_derived_iv(uVar2,0x16f,pcVar8,op3);
            }
            else if (uVar11 == 0x15f) {
              pcVar8 = get_derived_iv(uVar2,0x15f,pcVar8,op3);
            }
            if (uVar10 != 0x15f) {
              local_24 = tuple_new_binary_temp
                                   (uVar10,uVar2,pcVar13,pcVar8,tuple_insert_after,local_28);
            }
            pcVar6 = tuple_new(0x15b,uVar2,pcVar12,local_24->dst,tuple_insert_after,local_24);
          }
          else {
LAB_10746e17:
            if ((uVar10 == 0x16d) || (uVar10 == 0x16e)) {
              pcVar5 = (pcVar6->dst->sym->u18).expr;
              uVar10 = pcVar5->op;
              uVar15 = is_induction_variable_operand(pcVar5->operands);
              if (uVar15 == 0) {
                pcVar8 = pcVar5->operands;
                goto LAB_10746e9b;
              }
              pcVar13 = pcVar5->operands;
              pcVar8 = pcVar13->next;
              goto LAB_10746cea;
            }
            if (uVar10 != 0x15b) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0xd12);
            }
            pcVar8 = pcVar6->src;
LAB_10746e5e:
            pcVar8 = get_derived_iv(uVar2,uVar11,pcVar8,op3);
            pcVar6 = tuple_new(0x15b,uVar2,pcVar12,pcVar8,tuple_insert_after,local_28);
            number_assignment(pcVar6,1);
          }
          add_symbol_loop_def(pcVar3,pcVar6);
        }
      }
    }
    free_pending_iv_tuples();
    recse_loop_after_strength_reduction((c2_loop *)loop,fn);
    recompute_loop_liveness((c2_loop *)loop,0);
    find_basic_induction_variables((c2_loop *)loop);
    build_iv_def_use_lists((c2_loop *)loop);
    local_8 = local_8 + 1;
  } while (local_8 < 0x20);
  reset_iv_worklists();
  return;
}

