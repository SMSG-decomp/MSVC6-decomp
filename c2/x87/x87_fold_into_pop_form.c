c2_tuple * __fastcall x87_fold_into_pop_form(c2_tuple *t)

{
  c2_operand *pcVar1;
  int arith_index;
  int iVar2;
  uint32_t *stack_id_slot;
  uint fxch_slot;
  c2_tuple *scan;
  uint32_t uVar3;
  uint result_slot;
  uint src2_slot;
  c2_tuple *resume;
  
  scan = t->next;
  arith_index = x87_arith_op_index(t->op);
  if (-1 < arith_index) {
    if ((((((scan->op == 99) && (scan->src->kind == '\x01')) && (((scan->src->u18).reg)->id == 0x1f)
          ) && ((scan->dst->kind == '\x01' && (((scan->dst->u18).reg)->id == 0x20)))) &&
        ((pcVar1 = t->src, pcVar1->kind == '\x01' &&
         ((((pcVar1->u18).reg)->id == 0x1f && (pcVar1->next->kind == '\x01')))))) &&
       (((pcVar1->next->u18).reg)->id == 0x20)) {
      t->op = g_x87_arith_pop_form_table[arith_index];
      tuple_unlink_free(scan);
      tuple_swap_first_srcs(t);
      return t->next;
    }
    if (g_opt_favor_speed != 0) {
      pcVar1 = t->src->next;
      if ((pcVar1->kind != '\x01') || (uVar3 = ((pcVar1->u18).reg)->id, uVar3 == 0x1f)) {
        return t->next;
      }
      result_slot = 0;
      src2_slot = uVar3 - 0x1f;
      scan = t->next;
      resume = scan;
      for (; scan != (c2_tuple *)0x0; scan = scan->next) {
        switch(scan->kind) {
        case '\x11':
        case '\x16':
        case '\x17':
        case '\x18':
        case '\x1a':
          return resume;
        }
        uVar3 = scan->op;
        if (uVar3 == 0x5f) {
          fxch_slot = ((scan->src->u18).reg)->id - 0x1f;
          if (src2_slot == fxch_slot) {
            src2_slot = 0;
          }
          else if (src2_slot == 0) {
            src2_slot = fxch_slot;
          }
          if (result_slot == fxch_slot) {
            result_slot = 0;
          }
          else if (result_slot == 0) {
            result_slot = fxch_slot;
          }
        }
        else if ((scan->flags & 1) != 0) {
          if ((((scan->type & 0xf000) != 0x4000) && (scan->kind != '\x0e')) && (uVar3 != 0x5b)) {
            scan = x87_fold_into_pop_form_part(t,scan,src2_slot,result_slot,resume,arith_index);
            return scan;
          }
          if (uVar3 != 0x162) {
            if (((result_slot == 0) && (uVar3 == 99)) &&
               ((scan->dst->kind == '\x01' &&
                (((scan->dst->u18).reg)->id - 0x1f == (src2_slot & 0xffff))))) break;
            for (pcVar1 = scan->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
              if (((pcVar1->kind == '\x01') && ((pcVar1->type & 0xf000) == 0x4000)) &&
                 (((pcVar1->u18).reg)->id - 0x1f == (src2_slot & 0xffff))) {
                return resume;
              }
            }
            iVar2 = x87_stack_effect(scan);
            src2_slot = src2_slot + iVar2;
            result_slot = result_slot + iVar2;
            if ((int)src2_slot < 0) {
              return resume;
            }
            if ((int)result_slot < 0) {
              return resume;
            }
          }
        }
      }
      g_x87_tos = 7;
      g_x87_next_value_id = 0;
      stack_id_slot = g_x87_stack_ids + 7;
      do {
        *stack_id_slot = g_x87_next_value_id;
        stack_id_slot = stack_id_slot + -1;
        g_x87_next_value_id = g_x87_next_value_id + 1;
      } while (0x107990e7 < (int)stack_id_slot);
      iVar2 = x87_simulate_stack_ids(resume,scan->prev);
      if (iVar2 != -1) {
        stack_id_slot = g_x87_stack_ids + g_x87_tos;
        iVar2 = g_x87_tos - src2_slot;
        g_x87_tos = g_x87_tos + -1;
        g_x87_stack_ids[iVar2] = *stack_id_slot;
        x87_snapshot_stack();
        uVar3 = 0;
        stack_id_slot = g_x87_stack_ids + 7;
        do {
          *stack_id_slot = uVar3;
          stack_id_slot = stack_id_slot + -1;
          uVar3 = uVar3 + 1;
        } while (0x107990e7 < (int)stack_id_slot);
        g_x87_tos = 6;
        uVar3 = ((t->src->next->u18).reg)->id;
        t->op = g_x87_arith_pop_form_table[arith_index];
        g_x87_stack_ids[7 - (uVar3 - 0x1f)] = 0;
        tuple_swap_first_srcs(t);
        (t->dst->u18).reg = g_reg_symbols + uVar3;
        x87_legalize_and_fix_stack_dsts(t);
        x87_rewrite_stack_operands(t->next,scan->prev);
        x87_restore_stack_order(scan);
        tuple_unlink(scan);
        node_free((c2_node *)scan);
        return t;
      }
      return resume;
    }
  }
  return scan;
}

