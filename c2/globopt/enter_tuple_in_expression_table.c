void __fastcall enter_tuple_in_expression_table(c2_tuple *t,int32_t number_linked_dst)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint8_t cond;
  int iVar3;
  c2_symbol *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *t_00;
  c2_const_operand *pcVar7;
  c2_const_operand *pcVar8;
  uint32_t uVar9;
  c2_operand *local_14;
  c2_operand *pcStack_10;
  c2_operand *pcStack_c;
  c2_operand *pcStack_8;
  c2_operand *pcStack_4;
  
  cse_number_memory_bases(t);
  switch(t->kind) {
  case '\f':
    uVar9 = t->op;
    if (uVar9 != 0x15a) {
      if (uVar9 == 0x15b) {
        number_assignment(t,1);
        return;
      }
      if (uVar9 == 0x17d) {
        if ((t->u14).arg != (void *)0x0) {
          cond = compare_consumer_condition(t);
          uVar9 = expr_table_dispatch_by_kind(cond);
          pcVar4 = cse_find_or_make(uVar9,t->type,t->src,t->src->next);
          (t->u14).expr = pcVar4;
          return;
        }
        t_00 = find_next_use_of_dst(t,&local_14);
        iVar3 = node_has_side_effects((c2_node *)t);
        if ((iVar3 == 0) && (iVar3 = node_has_side_effects((c2_node *)t_00), iVar3 == 0)) {
          uVar9 = expr_table_dispatch_by_kind((t_00->u20).cc);
          pcVar4 = cse_find_or_make(uVar9,t->type,t->src,t->src->next);
          uVar1 = t_00->type;
          uVar9 = t_00->op;
          (t_00->u14).expr = pcVar4;
          pcStack_4 = operand_cse_key(t->src);
          pcStack_8 = operand_cse_key(t->src->next);
          pcStack_c = operand_cse_key(t_00->src->next);
          pcStack_10 = operand_cse_key(t_00->src->next->next);
          pcVar7 = operand_new_intconst(0x1004,(uint)t->type,0);
          pcVar8 = operand_new_intconst(0x1004,(uint)(t_00->u20).cc,0);
          pcVar4 = get_expression_symbol_n
                             (uVar9,uVar1,6,pcStack_4,pcStack_8,pcStack_c,pcStack_10,pcVar8,pcVar7);
          cse_bind_expression_result(pcVar4,t_00,uVar1,(int)t_00);
          return;
        }
      }
      else {
        iVar3 = node_has_side_effects((c2_node *)t);
        if ((iVar3 == 0) &&
           (((pcVar5 = t->dst, (1 << (pcVar5->kind & 0x1f) & 6U) == 0 ||
             (pcVar5->sym->def == (c2_tuple *)0x0)) || (number_linked_dst != 0)))) {
          if (((t->op == 0x16e) && ((pcVar5->type & 0xf000) == 0x1000)) &&
             (pcVar6 = t->src->next, pcVar6->kind == '\a')) {
            uVar2 = (pcVar6->u18).lo;
            (pcVar6->u18).lo = -uVar2;
            uVar9 = 0x16d;
            pcVar6->tag = -(pcVar6->tag + (uint)(uVar2 != 0));
            t->op = 0x16d;
          }
          uVar1 = pcVar5->type;
          pcVar5 = operand_cse_key(t->src);
          if (pcVar5 == (c2_operand *)0x0) {
            pcVar6 = (c2_operand *)0x0;
          }
          else {
            pcVar6 = operand_cse_key(t->src->next);
          }
          pcVar4 = cse_find_or_make(uVar9,uVar1,pcVar5,pcVar6);
          cse_bind_expression_result(pcVar4,t,uVar1,0);
        }
      }
    }
    break;
  case '\x12':
    if (((((g_intrinsic_desc[(t->u20).intrinsic.id].flags & 0x20) != 0) &&
         (t->dst != (c2_operand *)0x0)) &&
        (iVar3 = node_has_side_effects((c2_node *)t->dst), iVar3 == 0)) &&
       ((g_opt_basic == 0 || ((t->type & 0xf000) != 0x4000)))) {
      pcVar4 = cse_hash_call_or_intrinsic(t);
      cse_bind_expression_result(pcVar4,t,t->type,0);
    }
  case '\r':
  case '\x0e':
  case '\x15':
    pcVar5 = t->dst;
    if (((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0)) &&
       ((pcVar5->sym->def != (c2_tuple *)0x0 &&
        (find_next_use_of_dst(t,&local_14), (local_14->flags & 0x20) != 0)))) {
      cse_unlink_def(t);
      return;
    }
  }
  return;
}

