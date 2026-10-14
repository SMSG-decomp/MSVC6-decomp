c2_tuple * __fastcall x87_eliminate_fld_stack_copy(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *t_00;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  int iVar4;
  uint uVar5;
  uint32_t *puVar6;
  uint32_t uVar7;
  uint uVar8;
  
  if (g_opt_favor_speed == 0) {
    return t->next;
  }
  pcVar1 = t->next;
  uVar8 = ((t->src->u18).reg)->id - 0x1e;
  t_00 = pcVar1;
  do {
    if (t_00 == (c2_tuple *)0x0) {
LAB_107773ea:
      g_x87_next_value_id = 0;
      puVar6 = g_x87_stack_ids + 7;
      do {
        *puVar6 = g_x87_next_value_id;
        puVar6 = puVar6 + -1;
        g_x87_next_value_id = g_x87_next_value_id + 1;
      } while (0x107990e7 < (int)puVar6);
      g_x87_tos = 8;
      g_x87_stack_ids[8] = ((t->src->u18).reg)->id - 0x1f;
      iVar4 = x87_simulate_stack_ids(pcVar1,t_00->prev);
      if (iVar4 == -1) {
        return pcVar1;
      }
      iVar4 = g_x87_tos - ((t_00->dst->u18).reg)->id;
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
      x87_rewrite_stack_operands(pcVar1,t_00->prev);
      x87_restore_stack_order(t_00);
      pcVar1 = t->prev;
      tuple_unlink(t);
      node_free((c2_node *)t);
      tuple_unlink(t_00);
      node_free((c2_node *)t_00);
      return pcVar1->next;
    }
    switch(t_00->kind) {
    case '\x11':
    case '\x16':
    case '\x17':
    case '\x18':
    case '\x1a':
      goto switchD_1077739b_caseD_11;
    }
    uVar7 = t_00->op;
    if (uVar7 == 0x5f) {
      uVar5 = ((t_00->src->u18).reg)->id - 0x1f;
      if (uVar8 == uVar5) {
        uVar8 = 0;
      }
      else if (uVar8 == 0) {
        uVar8 = uVar5;
      }
    }
    else if (((t_00->flags & 1) != 0) &&
            ((((t_00->type & 0xf000) == 0x4000 || (t_00->kind == '\x0e')) || (uVar7 == 0x5b)))) {
      if (uVar8 == 0) {
        if (uVar7 == 99) {
          if (((t_00->dst->kind != '\x01') || (pcVar3 = (t_00->dst->u18).reg, pcVar3->cls != '\x01')
              ) || (pcVar3->id != 0x1f)) goto LAB_1075f152;
          goto LAB_107773ea;
        }
      }
      else {
LAB_1075f152:
        if (((uVar7 == 99) && (t_00->dst->kind == '\x01')) &&
           ((pcVar3 = (t_00->dst->u18).reg, pcVar3->cls == '\x01' &&
            (pcVar3->id - 0x1f == (uVar8 & 0xffff))))) goto LAB_107773ea;
      }
      for (pcVar2 = t_00->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((pcVar2->kind == '\x01') && ((pcVar2->type & 0xf000) == 0x4000)) &&
           (((pcVar2->u18).reg)->id - 0x1f == (uVar8 & 0xffff))) {
          return pcVar1;
        }
      }
      iVar4 = x87_stack_effect(t_00);
      uVar8 = uVar8 + iVar4;
      if ((int)uVar8 < 0) {
switchD_1077739b_caseD_11:
        return pcVar1;
      }
    }
    t_00 = t_00->next;
  } while( true );
}

