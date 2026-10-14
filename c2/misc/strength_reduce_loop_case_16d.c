void strength_reduce_loop_case_16d
               (uint32_t op,uint16_t type,c2_cse_expr *expr,uint32_t iv_op,c2_tuple *update,
               c2_tuple *div_value,c2_symbol *div_sym,c2_function *fn,c2_list_cell *def_cell,
               uint16_t line,c2_operand *div_opnd,c2_loop *loop,int round,c2_operand *factor)

{
  uint16_t type_00;
  c2_symbol *sym;
  c2_symbol *pcVar1;
  c2_cse_expr *pcVar2;
  c2_list_cell *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  uint32_t uVar6;
  c2_operand *pcVar7;
  c2_operand *src2;
  int iVar8;
  uint32_t uVar9;
  c2_tuple *pcVar10;
  c2_operand *in_stack_00000038;
  
code_r0x10746cd5:
  uVar9 = is_induction_variable_operand(expr->operands);
  if ((uVar9 == 0) && (op != 0x16e)) {
    pcVar4 = expr->operands;
    goto LAB_10746e9b;
  }
  pcVar7 = expr->operands;
  pcVar4 = pcVar7->next;
LAB_10746cea:
  in_stack_00000038 = get_derived_iv(type,iv_op,pcVar7,factor);
  if (iv_op == 0x16f) {
    pcVar4 = get_derived_iv(type,0x16f,pcVar4,factor);
  }
  else if (iv_op == 0x15f) {
    pcVar4 = get_derived_iv(type,0x15f,pcVar4,factor);
  }
  if (op != 0x15f) {
    div_value = tuple_new_binary_temp(op,type,in_stack_00000038,pcVar4,tuple_insert_after,update);
  }
  pcVar10 = tuple_new(0x15b,type,div_opnd,div_value->dst,tuple_insert_after,div_value);
  do {
    add_symbol_loop_def(div_sym,pcVar10);
    def_cell = def_cell->next;
    while (def_cell == (c2_list_cell *)0x0) {
      do {
        div_sym = div_sym->order_next;
        while (div_sym == (c2_symbol *)0xffffffff) {
          free_pending_iv_tuples();
          recse_loop_after_strength_reduction(loop,fn);
          recompute_loop_liveness(loop,0);
          find_basic_induction_variables(loop);
          build_iv_def_use_lists(loop);
          round = round + 1;
          if (0x1f < round) {
LAB_107469b4:
            reset_iv_worklists();
            return;
          }
          reset_iv_worklists();
          pcVar3 = collect_iv_candidates(loop,1);
          if (pcVar3 == (c2_list_cell *)0x0) goto LAB_107469b4;
          pcVar10 = iv_worklist_pop();
          while (div_sym = g_derived_iv_head, pcVar10 != (c2_tuple *)0x0) {
            if (pcVar10->line != 0) {
              g_current_line_abs = fn->line_base + (uint)pcVar10->line;
              g_cur_line = pcVar10->line;
            }
            type_00 = pcVar10->type;
            pcVar4 = get_derived_iv(type_00,pcVar10->op,pcVar10->src,pcVar10->src->next);
            sym = pcVar4->sym;
            pcVar1 = pcVar10->dst->sym;
            pcVar5 = tuple_new(0x15b,type_00,pcVar10->dst,pcVar4,tuple_insert_after,pcVar10);
            enter_tuple_in_expression_table(pcVar5,0);
            add_symbol_loop_use(sym,pcVar5);
            uVar9 = pcVar1->id;
            uVar6 = bitset_test(g_hoisted_exprs,uVar9);
            if ((uVar6 != 0) && (uVar9 = sparse_set_test_and_add(g_sr_seen_exprs,uVar9), uVar9 == 0)
               ) {
              bitset_set(g_sr_init_exprs,((pcVar5->u14).expr)->id);
            }
            sr_queue_dead_iv_tuples(pcVar10->dst,pcVar10);
            pcVar10 = iv_worklist_pop();
          }
        }
        if (line != 0) {
          g_current_line_abs = fn->line_base + (uint)line;
          g_cur_line = line;
        }
        pcVar2 = (div_sym->u18).expr;
        type = pcVar2->type;
        iv_op = map_iv_update_opcode(pcVar2->op);
        uVar9 = is_induction_variable_operand(pcVar2->operands);
        if (((uVar9 == 0) && (iv_op != 0x16e)) && (iv_op != 0x15f)) {
          factor = pcVar2->operands;
          pcVar4 = factor->next;
        }
        else {
          pcVar4 = pcVar2->operands;
          factor = pcVar4->next;
        }
        pcVar7 = materialize_value_in_preheader(type,pcVar4,g_preheader_insert_point,0);
        if (iv_op == 0x15f) {
          div_value = tuple_new_unary_temp
                                (0x15f,type,pcVar7,tuple_insert_before,g_preheader_insert_point);
        }
        else {
          src2 = materialize_value_in_preheader(type,factor,g_preheader_insert_point,0);
          div_value = tuple_new_binary_temp
                                (iv_op,type,pcVar7,src2,tuple_insert_before,g_preheader_insert_point
                                );
        }
        div_opnd = operand_new_sym(0x14a,type,div_sym);
        tuple_new(0x15b,type,div_opnd,div_value->dst,tuple_insert_before,g_preheader_insert_point);
      } while (pcVar4->kind != '\x02');
      def_cell = pcVar4->sym->defs;
    }
    pcVar10 = (def_cell->u04).tuple;
    update = pcVar10;
    if (((pcVar10->op == 0x16d) || (pcVar10->op == 0x16e)) &&
       ((pcVar10->next->op == 0x15b &&
        ((iVar8 = operand_compare(pcVar10->dst,pcVar10->next->src), iVar8 == 0 &&
         (iVar8 = operand_compare(pcVar10->next->dst,pcVar10->src), iVar8 == 0)))))) {
      update = pcVar10->next;
    }
    if (update->line != 0) {
      g_current_line_abs = fn->line_base + (uint)update->line;
      g_cur_line = update->line;
    }
    uVar9 = pcVar10->op;
    if (uVar9 == 0x15b) {
      pcVar4 = pcVar10->src;
      if (((1 << (pcVar4->kind & 0x1f) & 6U) == 0) ||
         (expr = (pcVar4->sym->u18).expr, expr == (c2_cse_expr *)0x0)) {
        if (((1 << (pcVar10->src->kind & 0x1f) & 6U) == 0) ||
           (pcVar5 = pcVar10->src->sym->def, pcVar5 == (c2_tuple *)0x0)) goto LAB_10746e17;
        op = pcVar5->op;
        pcVar7 = pcVar5->src;
        pcVar4 = pcVar7->next;
        goto LAB_10746cea;
      }
      op = expr->op;
      switch(op) {
      case 0x16d:
      case 0x16e:
        goto code_r0x10746cd5;
      default:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0xce9);
      case 0x179:
      case 0x17a:
        op = map_iv_update_opcode(op);
        goto code_r0x10746cd5;
      case 0x17b:
      case 0x17c:
      }
    }
    else {
LAB_10746e17:
      if ((uVar9 == 0x16d) || (uVar9 == 0x16e)) break;
      if (uVar9 != 0x15b) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0xd12);
      }
      pcVar4 = pcVar10->src;
    }
    pcVar4 = get_derived_iv(type,iv_op,pcVar4,factor);
    pcVar10 = tuple_new(0x15b,type,div_opnd,pcVar4,tuple_insert_after,update);
    number_assignment(pcVar10,1);
  } while( true );
  pcVar2 = (pcVar10->dst->sym->u18).expr;
  op = pcVar2->op;
  uVar9 = is_induction_variable_operand(pcVar2->operands);
  if (uVar9 == 0) {
    pcVar4 = pcVar2->operands;
LAB_10746e9b:
    pcVar7 = pcVar4->next;
  }
  else {
    pcVar7 = pcVar2->operands;
    pcVar4 = pcVar7->next;
  }
  goto LAB_10746cea;
}

