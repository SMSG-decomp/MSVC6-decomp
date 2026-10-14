c2_operand * __fastcall
compute_loop_trip_count
          (c2_loop *loop,c2_operand *iv,c2_tuple *anchor,c2_operand *limit,c2_tuple *cmp)

{
  uint16_t uVar1;
  c2_block *pcVar2;
  int iVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_operand *init;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  c2_tuple *t;
  c2_operand *pcVar9;
  c2_tuple *pcVar10;
  bool bVar11;
  
  uVar1 = cmp->type;
  pcVar2 = loop->first;
  t = (c2_tuple *)0x0;
  if (pcVar2 == loop->last->next) {
    return (c2_operand *)0x0;
  }
  do {
    pcVar10 = pcVar2->head->next;
    if (pcVar10 != pcVar2->end) {
      do {
        if (((pcVar10->op == 0x15b) && (iVar3 = operand_compare(pcVar10->dst,iv), iVar3 == 0)) &&
           (bVar11 = t != (c2_tuple *)0x0, t = pcVar10, bVar11)) {
          return (c2_operand *)0x0;
        }
        pcVar10 = pcVar10->next;
      } while (pcVar10 != pcVar2->end);
    }
    pcVar2 = pcVar2->next;
  } while (pcVar2 != loop->last->next);
  if (t == (c2_tuple *)0x0) {
    return (c2_operand *)0x0;
  }
  pcVar2 = tuple_get_block(t);
  if (pcVar2->loop != loop) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0x110a);
  }
  iVar3 = bitvec_test(loop->last->dominators,(int)pcVar2->rpo);
  if (iVar3 == 0) {
    return (c2_operand *)0x0;
  }
  pcVar10 = t->prev;
  if ((pcVar10->op != 0x16d) && (pcVar10->op != 0x16e)) {
    return (c2_operand *)0x0;
  }
  uVar4 = is_induction_variable_operand(pcVar10->src);
  if ((uVar4 == 0) || (uVar4 = is_loop_invariant_operand(pcVar10->src->next), uVar4 == 0)) {
    if (pcVar10->op != 0x16d) {
      return (c2_operand *)0x0;
    }
    uVar4 = is_loop_invariant_operand(pcVar10->src);
    if (uVar4 == 0) {
      return (c2_operand *)0x0;
    }
    uVar4 = is_induction_variable_operand(pcVar10->src->next);
    if (uVar4 == 0) {
      return (c2_operand *)0x0;
    }
    tuple_swap_first_srcs(pcVar10);
  }
  uVar4 = block_range_dominated(anchor,pcVar10);
  iVar3 = operand_compare(pcVar10->dst,t->src);
  if (iVar3 != 0) {
    return (c2_operand *)0x0;
  }
  iVar3 = operand_compare(t->dst,pcVar10->src);
  if (iVar3 != 0) {
    return (c2_operand *)0x0;
  }
  pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar10->src->next);
  if (pcVar5->kind != '\a') {
    return (c2_operand *)0x0;
  }
  if (pcVar10->op == 0x16e) {
    uVar7 = (pcVar5->u18).lo;
    (pcVar5->u18).lo = -uVar7;
    pcVar5->tag = -(pcVar5->tag + (uint)(uVar7 != 0));
  }
  init = evaluate_in_preheader(iv,loop);
  if (init == (c2_operand *)0x0) {
    return (c2_operand *)0x0;
  }
  if ((1 << (byte)(init->type >> 0xc) & 0xeU) == 0) {
    return (c2_operand *)0x0;
  }
  iVar3 = 0;
  pcVar9 = limit;
  switch((char)uVar1) {
  case '\x02':
    uVar7 = pcVar5->tag;
    uVar8 = (pcVar5->u18).lo;
    iVar3 = 1;
    if (((int)uVar7 < 1) && ((int)uVar7 < 0)) goto LAB_1076275f;
    goto LAB_107626c7;
  case '\x03':
    iVar3 = 1;
switchD_1076262a_caseD_5:
    if ((0 < (int)pcVar5->tag) ||
       ((-1 < (int)pcVar5->tag && ((pcVar5->u18).reg != (c2_symbol *)0x0)))) {
LAB_107626c7:
      iVar6 = types_compatible(init->type,pcVar9->type);
      if ((((iVar6 != 0) && ((init->type & 0xfff) < 5)) && ((pcVar9->type & 0xfff) < 5)) &&
         ((pcVar5->type & 0xfff) < 5)) {
        pcVar5 = build_trip_count_expression(loop,init,pcVar9,pcVar5,iVar3,uVar4,cmp);
        return pcVar5;
      }
    }
switchD_1076262a_default:
    return (c2_operand *)0x0;
  case '\x04':
    iVar3 = 1;
  case '\x06':
    uVar7 = pcVar5->tag;
    uVar8 = (pcVar5->u18).lo;
    if (-1 < (int)uVar7) {
      return (c2_operand *)0x0;
    }
LAB_1076275f:
    (pcVar5->u18).lo = -uVar8;
    pcVar5->tag = -(uVar7 + (uVar8 != 0));
    pcVar9 = init;
    init = limit;
    goto LAB_107626c7;
  case '\x05':
    goto switchD_1076262a_caseD_5;
  default:
    goto switchD_1076262a_default;
  }
}

