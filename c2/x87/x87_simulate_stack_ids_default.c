int x87_simulate_stack_ids_default
              (int fxch_pending,int tos,int fxch_seen,c2_tuple *cursor,c2_tuple *stop)

{
  c2_tuple *pcVar1;
  uint uVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  int iVar6;
  int iVar7;
  
  pcVar1 = cursor;
code_r0x1075c7dd:
  do {
    cursor = pcVar1;
    if (cursor == stop) {
      if (fxch_pending == 0) {
        return -2;
      }
      return 1;
    }
    pcVar1 = cursor->next;
  } while (((cursor->flags & 1) == 0) ||
          ((((cursor->type & 0xf000) != 0x4000 && (cursor->kind != '\x0e')) && (cursor->op != 0x5b))
          ));
  uVar2 = cursor->op;
  if (uVar2 < 0x163) goto code_r0x1075c826;
  if (uVar2 == 0x166) {
    return -1;
  }
  goto LAB_1075c836;
code_r0x1075c826:
  if (uVar2 != 0x162) {
    if (uVar2 == 0x5f) {
      uVar5 = g_x87_stack_ids[tos];
      iVar7 = ((cursor->src->u18).reg)->id - 0x1f;
      if (7 < iVar7) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x1a3);
      }
      iVar7 = tos - iVar7;
      g_x87_stack_ids[tos] = g_x87_stack_ids[iVar7];
      g_x87_stack_ids[iVar7] = uVar5;
      if ((fxch_pending == 0) && (fxch_seen == 0)) {
        fxch_seen = 1;
      }
      else {
        fxch_pending = 1;
        fxch_seen = 1;
      }
    }
    else if (uVar2 != 0x8e) {
LAB_1075c836:
      pcVar3 = cursor->src;
      pcVar4 = cursor->dst;
      fxch_seen = 0;
      for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->kind == '\x01') && ((pcVar3->type & 0xf000) == 0x4000)) {
          pcVar3->rank = g_x87_stack_ids[tos - (((pcVar3->u18).reg)->id - 0x1f)];
        }
      }
      if ((pcVar4->kind == '\x01') && ((pcVar4->type & 0xf000) == 0x4000)) {
        iVar7 = ((pcVar4->u18).reg)->id - 0x1f;
      }
      else {
        iVar7 = 0;
      }
      iVar6 = x87_stack_effect(cursor);
      tos = g_x87_tos;
      switch(iVar6) {
      case 0:
        uVar5 = g_x87_next_value_id + 1;
        iVar7 = g_x87_tos - iVar7;
        g_x87_next_value_id = uVar5;
        pcVar4->rank = uVar5;
        g_x87_stack_ids[iVar7] = uVar5;
        break;
      case 1:
        if (0xf < g_x87_tos) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x415);
        }
        uVar5 = g_x87_next_value_id + 1;
        tos = g_x87_tos + 1;
        g_x87_tos = tos;
        g_x87_next_value_id = uVar5;
        g_x87_stack_ids[tos] = uVar5;
        pcVar4->rank = uVar5;
        break;
      case -2:
        uVar5 = g_x87_next_value_id + 1;
        tos = g_x87_tos + -2;
        g_x87_next_value_id = uVar5;
        pcVar4->rank = uVar5;
        g_x87_stack_ids[g_x87_tos - iVar7] = uVar5;
        g_x87_tos = tos;
        break;
      case -1:
        uVar5 = g_x87_next_value_id + 1;
        tos = g_x87_tos + -1;
        g_x87_next_value_id = uVar5;
        pcVar4->rank = uVar5;
        g_x87_stack_ids[g_x87_tos - iVar7] = uVar5;
        g_x87_tos = tos;
      }
    }
  }
  goto code_r0x1075c7dd;
}

