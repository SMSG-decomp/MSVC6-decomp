void __fastcall x87_rewrite_stack_operands(c2_tuple *t,c2_tuple *t2)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  int dst_slot;
  int iVar4;
  int iVar5;
  uint32_t id;
  int iVar6;
  c2_tuple *next;
  c2_tuple *end;
  
  end = t2->next;
  if (t != end) {
    do {
      next = t->next;
      if (((t->flags & 1) == 0) ||
         (((((t->type & 0xf000) != 0x4000 && (t->kind != '\x0e')) && (t->op != 0x5b)) ||
          (t->op == 0x162)))) goto code_r0x1075f2e9;
      if (t->op == 0x5f) {
        tuple_unlink(t);
        node_free((c2_node *)t);
        goto code_r0x1075f2e9;
      }
      pcVar1 = t->dst;
      if ((pcVar1->kind == '\x01') && ((pcVar1->type & 0xf000) == 0x4000)) {
        dst_slot = ((pcVar1->u18).reg)->id - 0x1f;
      }
      else {
        dst_slot = 0;
      }
      iVar4 = x87_op_requires_st0(t);
      if (iVar4 != 0) {
        pcVar2 = t->src;
        pcVar3 = pcVar2->next;
        if (pcVar3 == (c2_operand *)0x0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x456);
        }
        if (pcVar3->kind != '\x01') {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x457);
        }
        iVar5 = ((pcVar2->u18).reg)->id - 0x1f;
        iVar6 = ((pcVar3->u18).reg)->id - 0x1f;
        if (iVar5 == 0) {
          if (iVar6 < 1) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x45b);
          }
          iVar5 = x87_depth_of_value(pcVar3->rank);
          x87_insert_fxch_pair(t,iVar5,iVar6);
          id = pcVar2->rank;
        }
        else {
          if (iVar6 != 0) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x45f);
          }
          iVar6 = x87_depth_of_value(pcVar2->rank);
          x87_insert_fxch_pair(t,iVar6,iVar5);
          id = pcVar3->rank;
        }
        iVar5 = x87_depth_of_value(id);
        x87_insert_fxch(t,iVar5);
      }
      pcVar2 = t->src;
      while ((pcVar2 != (c2_operand *)0x0 && (iVar4 == 0))) {
        if ((pcVar2->kind == '\x01') && ((pcVar2->type & 0xf000) == 0x4000)) {
          iVar6 = ((pcVar2->u18).reg)->id - 0x1f;
          iVar5 = x87_depth_of_value(pcVar2->rank);
          if (iVar6 == 0) {
            x87_insert_fxch(t,iVar5);
          }
          else if (t->kind == '\x0e') {
            if (iVar6 != iVar5) {
              x87_insert_fxch(t,iVar6);
              x87_insert_fxch(t,iVar5);
              x87_insert_fxch(t,iVar6);
            }
          }
          else {
            if (iVar5 == 0) {
              if (pcVar2 != t->src) {
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x476);
              }
              pcVar3 = pcVar2->next;
              if (pcVar3 == (c2_operand *)0x0) {
                if (t->op != 0x60) {
                  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x47f);
                }
                iVar5 = 0;
              }
              else {
                if (pcVar3->kind != '\x01') {
                  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x478);
                }
                iVar5 = x87_depth_of_value(pcVar3->rank);
                if (iVar5 < 1) {
                  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x47a);
                }
                x87_insert_fxch(t,iVar5);
                (pcVar2->next->u18).reg = (c2_symbol *)0x107ad15c;
              }
            }
            (pcVar2->u18).reg = g_reg_symbols + iVar5 + 0x1f;
            if (dst_slot == iVar6) {
              (pcVar1->u18).reg = g_reg_symbols + iVar5 + 0x1f;
              dst_slot = iVar5;
            }
          }
        }
        pcVar2 = pcVar2->next;
      }
      iVar4 = x87_stack_effect(t);
      switch(iVar4) {
      case 0:
        g_x87_stack_ids[g_x87_tos - dst_slot] = pcVar1->rank;
        break;
      case 1:
        if (0xf < g_x87_tos) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\fppeeps.c",0x490);
        }
        g_x87_tos = g_x87_tos + 1;
        g_x87_stack_ids[g_x87_tos] = t->dst->rank;
        x87_rewrite_stack_operands_default(dst_slot,next,end);
        return;
      case -2:
        iVar4 = g_x87_tos - dst_slot;
        g_x87_tos = g_x87_tos + -2;
        g_x87_stack_ids[iVar4] = pcVar1->rank;
        goto LAB_10777ce1;
      case -1:
        iVar4 = g_x87_tos - dst_slot;
        g_x87_tos = g_x87_tos + -1;
        g_x87_stack_ids[iVar4] = pcVar1->rank;
LAB_10777ce1:
        x87_rewrite_stack_operands_default(dst_slot,next,end);
        return;
      }
code_r0x1075f2e9:
      t = next;
    } while (t != end);
  }
  return;
}

