c2_tuple *
x87_eliminate_fld_stack_copy_part
          (c2_tuple *cursor,uint copy_slot,c2_tuple *fld,uint8_t one,c2_tuple *resume)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  uint uVar5;
  uint32_t *puVar6;
  uint32_t uVar7;
  
  do {
    do {
      while( true ) {
        cursor = cursor->next;
        if (cursor == (c2_tuple *)0x0) goto LAB_107773ea;
        switch(cursor->kind) {
        case '\x11':
        case '\x16':
        case '\x17':
        case '\x18':
        case '\x1a':
          goto switchD_1077739b_caseD_11;
        }
        uVar7 = cursor->op;
        if (uVar7 != 0x5f) break;
        uVar5 = ((cursor->src->u18).reg)->id - 0x1f;
        if (copy_slot == uVar5) {
          copy_slot = 0;
        }
        else if (copy_slot == 0) {
          copy_slot = uVar5;
        }
      }
    } while (((cursor->flags & one) == 0) ||
            ((((cursor->type & 0xf000) != 0x4000 && (cursor->kind != '\x0e')) && (uVar7 != 0x5b))));
    if (copy_slot == 0) {
      if (uVar7 == 99) {
        if (((cursor->dst->kind == one) && (pcVar2 = (cursor->dst->u18).reg, pcVar2->cls == one)) &&
           (pcVar2->id == 0x1f)) goto LAB_107773ea;
        goto LAB_1075f152;
      }
    }
    else {
LAB_1075f152:
      if (((uVar7 == 99) && (cursor->dst->kind == one)) &&
         ((pcVar2 = (cursor->dst->u18).reg, pcVar2->cls == one &&
          (pcVar2->id - 0x1f == (copy_slot & 0xffff))))) {
LAB_107773ea:
        g_x87_next_value_id = 0;
        puVar6 = g_x87_stack_ids + 7;
        do {
          *puVar6 = g_x87_next_value_id;
          puVar6 = puVar6 + -1;
          g_x87_next_value_id = g_x87_next_value_id + 1;
        } while (0x107990e7 < (int)puVar6);
        g_x87_tos = 8;
        g_x87_stack_ids[8] = ((fld->src->u18).reg)->id - 0x1f;
        iVar4 = x87_simulate_stack_ids(resume,cursor->prev);
        if (iVar4 == -1) {
          return resume;
        }
        iVar4 = g_x87_tos - ((cursor->dst->u18).reg)->id;
        puVar6 = g_x87_stack_ids + g_x87_tos;
        g_x87_tos = g_x87_tos + -1;
        g_x87_saved_stack_ids[iVar4 + 0xf] = *puVar6;
        x87_snapshot_stack();
        g_x87_tos = 7;
        uVar7 = 0;
        puVar6 = g_x87_stack_ids + 7;
        do {
          *puVar6 = uVar7;
          puVar6 = puVar6 + -1;
          uVar7 = uVar7 + 1;
        } while (0x107990e7 < (int)puVar6);
        x87_rewrite_stack_operands(resume,cursor->prev);
        x87_restore_stack_order(cursor);
        pcVar3 = fld->prev;
        tuple_unlink(fld);
        node_free((c2_node *)fld);
        tuple_unlink(cursor);
        node_free((c2_node *)cursor);
        return pcVar3->next;
      }
    }
    for (pcVar1 = cursor->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      if (((pcVar1->kind == one) && ((pcVar1->type & 0xf000) == 0x4000)) &&
         (((pcVar1->u18).reg)->id - 0x1f == (copy_slot & 0xffff))) {
        return resume;
      }
    }
    iVar4 = x87_stack_effect(cursor);
    copy_slot = copy_slot + iVar4;
  } while (-1 < (int)copy_slot);
switchD_1077739b_caseD_11:
  return resume;
}

