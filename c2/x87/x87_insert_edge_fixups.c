void __fastcall
x87_insert_edge_fixups
          (c2_loop *loop,c2_tuple *t,c2_symbol *sym,c2_bitset *x87_ranges,c2_function *fn)

{
  byte bVar1;
  int16_t iVar2;
  uint16_t type;
  uint32_t uVar3;
  c2_loop_exit *pcVar4;
  c2_block *pred;
  c2_edge *pcVar5;
  c2_block *succ;
  c2_loop *pcVar6;
  c2_edge *edge;
  uint32_t uVar7;
  c2_block *pcVar8;
  c2_bitset *pcVar9;
  c2_live_range **pred_slot;
  c2_live_range **next_slot;
  c2_live_range **slot_ptr;
  c2_tuple *pcVar10;
  c2_operand *src;
  c2_operand *dst;
  c2_tuple *pcVar11;
  int top_slot;
  c2_operand *opnd;
  c2_loop *pcVar12;
  c2_loop *exit_loop;
  int sym_slot;
  c2_live_range *slot_range;
  c2_insert_fn *insert_fn;
  
  exit_loop = loop;
  if (loop->parent != (c2_loop *)0x0) {
    uVar3 = ((sym->u30).ra)->id;
    pcVar6 = loop->parent;
    exit_loop = loop;
    do {
      pcVar12 = pcVar6;
      uVar7 = bitset_test(pcVar12->candidates,uVar3);
      if (uVar7 != 0) break;
      pcVar6 = pcVar12->parent;
      exit_loop = pcVar12;
    } while (pcVar12->parent != (c2_loop *)0x0);
  }
  pcVar4 = exit_loop->exits;
  opnd = (c2_operand *)sym;
joined_r0x107793f5:
  if (pcVar4 == (c2_loop_exit *)0x0) {
    tuple_unlink_free(t);
    return;
  }
  pred = pcVar4->block;
  pcVar5 = pred->succs;
joined_r0x1077940f:
  do {
    edge = pcVar5;
    if (edge == (c2_edge *)0x0) break;
    pcVar5 = edge->next_succ;
    succ = edge->to;
    if (succ->loop != exit_loop) {
      pcVar8 = succ;
      if (succ->preds->next_pred != (c2_edge *)0x0) {
        pcVar8 = split_edge_with_new_block(fn,edge,pred,succ);
        pred_slot = (c2_live_range **)succ->live_in;
        pcVar9 = bitset_clone((c2_bitset *)pred_slot);
        pcVar8->live_in = pcVar9;
        bitset_andnot(pcVar9,x87_ranges);
        pcVar9 = bitset_clone((c2_bitset *)pred_slot);
        pcVar8->live_out = pcVar9;
        bitset_andnot(pcVar9,x87_ranges);
        pred_slot = (c2_live_range **)bitset_clone((c2_bitset *)pred_slot);
        pcVar8->live = (c2_bitset *)pred_slot;
        bitset_andnot((c2_bitset *)pred_slot,x87_ranges);
        pred_slot = (c2_live_range **)bitset_new(8);
        pcVar8->set24 = (c2_bitset *)pred_slot;
        pred_slot = (c2_live_range **)bitset_new(8);
        pcVar8->set28 = (c2_bitset *)pred_slot;
        pred_slot = (c2_live_range **)bitset_new(6);
        iVar2 = succ->loop_depth;
        pcVar8->set4c = (c2_bitset *)pred_slot;
        pcVar6 = succ->loop;
        pcVar8->loop_depth = iVar2;
        pcVar8->loop = pcVar6;
        next_slot = arena_alloc(4,0x20);
        (pcVar8->u58).x87_stack = (c2_x87_block_stack *)next_slot;
        slot_ptr = (c2_live_range **)(pred->u58).x87_stack;
        for (top_slot = 8; top_slot != 0; top_slot = top_slot + -1) {
          *next_slot = *slot_ptr;
          slot_ptr = slot_ptr + 1;
          next_slot = next_slot + 1;
        }
      }
      pcVar11 = pcVar8->head;
      for (pcVar10 = pcVar11; pcVar10 != pcVar8->end; pcVar10 = pcVar10->next) {
        if ((pcVar10->flags & 1) != 0) {
          for (opnd = pcVar10->src; (c2_symbol *)opnd != (c2_symbol *)0x0;
              opnd = (c2_operand *)((c2_fe_symbol *)opnd)->next) {
            if ((*(uint8_t *)&((c2_fe_symbol *)opnd)->storage_sym == '\x01') &&
               ((c2_symbol *)((c2_fe_symbol *)opnd)->attrs == sym)) goto LAB_10779539;
          }
          for (opnd = pcVar10->dst; (c2_symbol *)opnd != (c2_symbol *)0x0;
              opnd = (c2_operand *)((c2_fe_symbol *)opnd)->next) {
            if (((*(uint8_t *)&((c2_fe_symbol *)opnd)->storage_sym == '\x01') &&
                ((c2_symbol *)((c2_fe_symbol *)opnd)->attrs == sym)) && (pcVar10->op != 0x5f)) {
              opnd = (c2_operand *)0x0;
              goto LAB_107795a6;
            }
          }
        }
      }
LAB_10779539:
      if (((c2_symbol *)opnd != (c2_symbol *)0x0) &&
         ((uVar3 = pcVar10->op, uVar3 == 0x62 || (uVar3 == 99)))) {
        if ((pcVar10->dst->kind == '\x02') && (pcVar10->dst->sym == sym)) goto joined_r0x1077940f;
        if (uVar3 == 99) {
          tuple_replace_dst(pcVar10,pcVar10->dst,t->dst);
          goto joined_r0x1077940f;
        }
      }
LAB_107795a6:
      top_slot = 0;
      sym_slot = 0;
      slot_ptr = (c2_live_range **)(pred->u58).x87_stack;
      if (((c2_x87_block_stack *)slot_ptr)->slot[0]->fe == (c2_fe_symbol *)sym) {
LAB_10779689:
        slot_ptr = (c2_live_range **)(((pred->u58).x87_stack)->slot + sym_slot + 1);
        slot_range = (c2_live_range *)((pred->u58).x87_stack)->slot[sym_slot + 1];
        top_slot = sym_slot;
        while (slot_range != (c2_live_range *)0x0) {
          next_slot = slot_ptr + 1;
          slot_ptr = slot_ptr + 1;
          top_slot = top_slot + 1;
          slot_range = *next_slot;
        }
      }
      else {
        do {
          next_slot = slot_ptr + 1;
          slot_ptr = slot_ptr + 1;
          top_slot = top_slot + 1;
        } while ((*next_slot)->sym != sym);
        sym_slot = top_slot;
        if (top_slot != 7) goto LAB_10779689;
      }
      bVar1 = pcVar11->flags;
      while ((((bVar1 & 1) == 0 && (pcVar11->kind != '\x18')) && (pcVar11 != pcVar8->end))) {
        pcVar11 = pcVar11->next;
        bVar1 = pcVar11->flags;
      }
      pcVar10 = (c2_tuple *)node_clone((c2_node *)t);
      tuple_insert_before(pcVar11,pcVar10);
      if (top_slot != sym_slot) {
        type = pcVar10->type;
        insert_fn = tuple_insert_before;
        pcVar11 = pcVar10;
        src = operand_new_reg(0x149,type,(c2_symbol *)((pred->u58).x87_stack)->slot[top_slot]->fe,
                              g_reg_symbols + (top_slot - sym_slot) + 0x1f);
        dst = operand_new_reg(0x149,type,sym,g_reg_symbols + 0x1f);
        pcVar11 = tuple_new(0x5f,type,dst,src,insert_fn,pcVar11);
        pcVar11 = (c2_tuple *)node_clone((c2_node *)pcVar11);
        tuple_insert_after(pcVar10,pcVar11);
      }
    }
  } while( true );
  pcVar4 = pcVar4->next;
  goto joined_r0x107793f5;
}

