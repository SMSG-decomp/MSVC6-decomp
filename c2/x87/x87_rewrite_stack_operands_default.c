void x87_rewrite_stack_operands_default(int dst_slot,c2_tuple *next,c2_tuple *end)

{
  c2_tuple *next_00;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  uint32_t id;
  int iVar5;
  int in_stack_0000001c;
  
  next_00 = next;
  do {
    while( true ) {
      do {
        next = next_00;
        if (next == end) {
          return;
        }
        next_00 = next->next;
      } while (((next->flags & 1) == 0) ||
              (((((next->type & 0xf000) != 0x4000 && (next->kind != '\x0e')) && (next->op != 0x5b))
               || (next->op == 0x162))));
      if (next->op != 0x5f) break;
      tuple_unlink(next);
      node_free((c2_node *)next);
    }
    pcVar1 = next->dst;
    if ((pcVar1->kind == '\x01') && ((pcVar1->type & 0xf000) == 0x4000)) {
      dst_slot = ((pcVar1->u18).reg)->id - 0x1f;
    }
    else {
      dst_slot = 0;
    }
    in_stack_0000001c = x87_op_requires_st0(next);
    if (in_stack_0000001c != 0) {
      pcVar2 = next->src;
      pcVar3 = pcVar2->next;
      if (pcVar3 == (c2_operand *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x456);
      }
      if (pcVar3->kind != '\x01') {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x457);
      }
      iVar4 = ((pcVar2->u18).reg)->id - 0x1f;
      iVar5 = ((pcVar3->u18).reg)->id - 0x1f;
      if (iVar4 == 0) {
        if (iVar5 < 1) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x45b);
        }
        iVar4 = x87_depth_of_value(pcVar3->rank);
        x87_insert_fxch_pair(next,iVar4,iVar5);
        id = pcVar2->rank;
      }
      else {
        if (iVar5 != 0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x45f);
        }
        iVar5 = x87_depth_of_value(pcVar2->rank);
        x87_insert_fxch_pair(next,iVar5,iVar4);
        id = pcVar3->rank;
      }
      iVar4 = x87_depth_of_value(id);
      x87_insert_fxch(next,iVar4);
    }
    pcVar2 = next->src;
    while ((pcVar2 != (c2_operand *)0x0 && (in_stack_0000001c == 0))) {
      if ((pcVar2->kind == '\x01') && ((pcVar2->type & 0xf000) == 0x4000)) {
        iVar5 = ((pcVar2->u18).reg)->id - 0x1f;
        iVar4 = x87_depth_of_value(pcVar2->rank);
        if (iVar5 == 0) {
          x87_insert_fxch(next,iVar4);
        }
        else if (next->kind == '\x0e') {
          if (iVar5 != iVar4) {
            x87_insert_fxch(next,iVar5);
            x87_insert_fxch(next,iVar4);
            x87_insert_fxch(next,iVar5);
          }
        }
        else {
          if (iVar4 == 0) {
            if (pcVar2 != next->src) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x476);
            }
            pcVar3 = pcVar2->next;
            if (pcVar3 == (c2_operand *)0x0) {
              if (next->op != 0x60) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x47f);
              }
              iVar4 = 0;
            }
            else {
              if (pcVar3->kind != '\x01') {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x478);
              }
              iVar4 = x87_depth_of_value(pcVar3->rank);
              if (iVar4 < 1) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x47a);
              }
              x87_insert_fxch(next,iVar4);
              (pcVar2->next->u18).reg = (c2_symbol *)0x107ad15c;
            }
          }
          (pcVar2->u18).reg = g_reg_symbols + iVar4 + 0x1f;
          if (dst_slot == iVar5) {
            (pcVar1->u18).reg = g_reg_symbols + iVar4 + 0x1f;
            dst_slot = iVar4;
          }
        }
      }
      pcVar2 = pcVar2->next;
    }
    iVar4 = x87_stack_effect(next);
    switch(iVar4) {
    case 0:
      g_x87_stack_ids[g_x87_tos - dst_slot] = pcVar1->rank;
      break;
    case 1:
      if (0xf < g_x87_tos) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x490);
      }
      g_x87_tos = g_x87_tos + 1;
      g_x87_stack_ids[g_x87_tos] = next->dst->rank;
      x87_rewrite_stack_operands_default(dst_slot,next_00,end);
      return;
    case -2:
      iVar4 = g_x87_tos - dst_slot;
      g_x87_tos = g_x87_tos + -2;
      g_x87_stack_ids[iVar4] = pcVar1->rank;
LAB_10777ce1:
      x87_rewrite_stack_operands_default(dst_slot,next_00,end);
      return;
    case -1:
      iVar4 = g_x87_tos - dst_slot;
      g_x87_tos = g_x87_tos + -1;
      g_x87_stack_ids[iVar4] = pcVar1->rank;
      goto LAB_10777ce1;
    }
  } while( true );
}

