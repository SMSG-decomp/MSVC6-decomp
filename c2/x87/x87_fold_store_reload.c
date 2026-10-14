c2_tuple * __fastcall x87_fold_store_reload(c2_tuple *t,int pop_op_index)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint32_t *puVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint uVar10;
  c2_symbol *pcVar11;
  c2_symbol *pcVar12;
  
  uVar10 = 0;
  t_00 = t->prev;
  do {
    iVar4 = pop_op_index;
    if (t_00 == (c2_tuple *)0x0) goto LAB_10777558;
    switch(t_00->kind) {
    case '\x11':
    case '\x16':
    case '\x17':
    case '\x18':
    case '\x1a':
      goto switchD_1077752c_caseD_11;
    }
    uVar9 = t_00->op;
    if (uVar9 == 0x5f) {
      uVar5 = ((t_00->src->u18).reg)->id - 0x1f;
      if (uVar10 == uVar5) {
        uVar10 = 0;
      }
      else if (uVar10 == 0) {
        uVar10 = uVar5;
      }
    }
    else if ((((t_00->flags & 1) != 0) &&
             ((((t_00->type & 0xf000) == 0x4000 || (t_00->kind == '\x0e')) || (uVar9 == 0x5b)))) &&
            (uVar9 != 0x162)) {
      if ((uVar10 == 0) && (uVar9 == 0x60)) {
        pcVar3 = t_00->src;
        if (pcVar3->kind == '\x01') {
          return t->next;
        }
        if (pcVar3->type == 0x400a) {
          return t->next;
        }
        if (pcVar3->kind == '\x06') {
          if (pcVar3->base == (c2_operand *)0x0) {
            pcVar11 = (c2_symbol *)0x0;
          }
          else {
            pcVar11 = (pcVar3->base->u18).reg;
          }
          if (pcVar3->index == (c2_operand *)0x0) {
            pcVar12 = (c2_symbol *)0x0;
          }
          else {
            pcVar12 = (pcVar3->index->u18).reg;
          }
          for (pcVar2 = t_00->next; pcVar2 != t; pcVar2 = pcVar2->next) {
            for (pcVar1 = pcVar2->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
              if ((pcVar1->kind == '\x01') &&
                 (((pcVar1->u18).reg == pcVar11 || ((pcVar1->u18).reg == pcVar12)))) {
                return t->next;
              }
            }
          }
        }
        for (pcVar2 = t_00->next; pcVar2 != t; pcVar2 = pcVar2->next) {
          for (pcVar1 = pcVar2->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
            iVar4 = operands_may_alias(pcVar1,pcVar3);
            if (iVar4 != 0) {
              return t->next;
            }
          }
        }
        iVar4 = 0;
LAB_10777558:
        x87_legalize_and_fix_stack_dsts(t);
        puVar7 = g_x87_stack_ids + 7;
        uVar9 = 0;
        do {
          uVar8 = uVar9;
          *puVar7 = uVar8;
          puVar7 = puVar7 + -1;
          uVar9 = uVar8 + 1;
        } while (0x107990e7 < (int)puVar7);
        if (iVar4 == 0) {
          g_x87_next_value_id = uVar8 + 2;
          g_x87_stack_ids[8] = uVar9;
        }
        else {
          g_x87_stack_ids[8] = ((t_00->src->u18).reg)->id - 0x1f;
          g_x87_next_value_id = uVar9;
        }
        g_x87_tos = 8;
        iVar6 = x87_simulate_stack_ids(t_00->next,t);
        if (iVar6 != -1) {
          x87_snapshot_stack();
          if ((pop_op_index == 2) || (pop_op_index == 3)) {
            if (t_00->op == 0x60) {
              uVar9 = g_x87_arith_mem_operand_form_table[pop_op_index];
              goto LAB_107775d7;
            }
          }
          else if (t_00->op == 0x60) {
            uVar9 = g_x87_arith_mem_operand_form_table[pop_op_index];
            goto LAB_107775d7;
          }
          uVar9 = g_x87_pop_to_int_operand_form_table[pop_op_index];
LAB_107775d7:
          pcVar3 = t->dst;
          t->op = uVar9;
          pcVar1 = t->src;
          (pcVar1->u18).reg = g_reg_symbols + 0x1f;
          (pcVar3->u18).reg = g_reg_symbols + 0x1f;
          if (iVar4 == 0) {
            tuple_replace_src(t,pcVar1->next,t_00->src);
          }
          else {
            (pcVar1->next->u18).reg = (c2_symbol *)0x107ad204;
          }
          t->type = t_00->type;
          x87_legalize_and_fix_stack_dsts(t);
          g_x87_tos = 7;
          uVar9 = 0;
          puVar7 = g_x87_stack_ids + 7;
          do {
            *puVar7 = uVar9;
            puVar7 = puVar7 + -1;
            uVar9 = uVar9 + 1;
          } while (0x107990e7 < (int)puVar7);
          x87_rewrite_stack_operands(t_00->next,t);
          pcVar2 = t->next;
          x87_restore_stack_order(pcVar2);
          tuple_unlink(t_00);
          node_free((c2_node *)t_00);
          return pcVar2;
        }
switchD_1077752c_caseD_11:
        return t->next;
      }
      iVar4 = x87_stack_effect(t_00);
      uVar10 = uVar10 - iVar4;
      if ((int)uVar10 < 0) goto switchD_1077752c_caseD_11;
      for (pcVar3 = t_00->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (((pcVar3->kind == '\x01') && ((pcVar3->type & 0xf000) == 0x4000)) &&
           (((pcVar3->u18).reg)->id - 0x1f == (uVar10 & 0xffff))) goto switchD_1077752c_caseD_11;
      }
    }
    t_00 = t_00->prev;
  } while( true );
}

