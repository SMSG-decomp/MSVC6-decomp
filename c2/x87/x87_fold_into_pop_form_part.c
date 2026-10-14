c2_tuple * __fastcall
x87_fold_into_pop_form_part
          (c2_tuple *t,c2_tuple *cursor,uint src2_slot,uint result_slot,c2_tuple *resume,
          int arith_index)

{
  c2_operand *pcVar1;
  uint32_t *stack_id_slot;
  int iVar2;
  uint uVar3;
  c2_tuple *pcVar4;
  uint32_t uVar5;
  
  while (cursor = cursor->next, cursor != (c2_tuple *)0x0) {
    switch(cursor->kind) {
    case '\x11':
    case '\x16':
    case '\x17':
    case '\x18':
    case '\x1a':
      return resume;
    }
    uVar5 = cursor->op;
    if (uVar5 == 0x5f) {
      uVar3 = ((cursor->src->u18).reg)->id - 0x1f;
      if (src2_slot == uVar3) {
        src2_slot = 0;
      }
      else if (src2_slot == 0) {
        src2_slot = uVar3;
      }
      if (result_slot == uVar3) {
        result_slot = 0;
      }
      else if (result_slot == 0) {
        result_slot = uVar3;
      }
    }
    else if ((cursor->flags & 1) != 0) {
      if ((((cursor->type & 0xf000) != 0x4000) && (cursor->kind != '\x0e')) && (uVar5 != 0x5b)) {
        pcVar4 = x87_fold_into_pop_form_part(t,cursor,src2_slot,result_slot,resume,arith_index);
        return pcVar4;
      }
      if (uVar5 != 0x162) {
        if (((result_slot == 0) && (uVar5 == 99)) &&
           ((cursor->dst->kind == '\x01' &&
            (((cursor->dst->u18).reg)->id - 0x1f == (src2_slot & 0xffff))))) break;
        for (pcVar1 = cursor->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if (((pcVar1->kind == '\x01') && ((pcVar1->type & 0xf000) == 0x4000)) &&
             (((pcVar1->u18).reg)->id - 0x1f == (src2_slot & 0xffff))) {
            return resume;
          }
        }
        iVar2 = x87_stack_effect(cursor);
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
  iVar2 = x87_simulate_stack_ids(resume,cursor->prev);
  if (iVar2 != -1) {
    stack_id_slot = g_x87_stack_ids + g_x87_tos;
    iVar2 = g_x87_tos - src2_slot;
    g_x87_tos = g_x87_tos + -1;
    g_x87_stack_ids[iVar2] = *stack_id_slot;
    x87_snapshot_stack();
    uVar5 = 0;
    stack_id_slot = g_x87_stack_ids + 7;
    do {
      *stack_id_slot = uVar5;
      stack_id_slot = stack_id_slot + -1;
      uVar5 = uVar5 + 1;
    } while (0x107990e7 < (int)stack_id_slot);
    g_x87_tos = 6;
    uVar5 = ((t->src->next->u18).reg)->id;
    t->op = g_x87_arith_pop_form_table[arith_index];
    g_x87_stack_ids[7 - (uVar5 - 0x1f)] = 0;
    tuple_swap_first_srcs(t);
    (t->dst->u18).reg = g_reg_symbols + uVar5;
    x87_legalize_and_fix_stack_dsts(t);
    x87_rewrite_stack_operands(t->next,cursor->prev);
    x87_restore_stack_order(cursor);
    tuple_unlink(cursor);
    node_free((c2_node *)cursor);
    return t;
  }
  return resume;
}

