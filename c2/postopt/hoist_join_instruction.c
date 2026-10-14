c2_tuple * __fastcall hoist_join_instruction(c2_tuple *jmp)

{
  c2_tuple *t;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  bool bVar4;
  c2_tuple *t_00;
  c2_tuple *t_01;
  int iVar5;
  c2_tuple *t_02;
  c2_tuple *pcVar6;
  c2_tuple *jcc;
  
  bVar4 = true;
  t_00 = tuple_prev_real_in_block(jmp);
  if ((((((jmp->src->kind == '\x04') &&
         (t = *(c2_tuple **)&(jmp->src->sym->u30).globopt.marks, t != (c2_tuple *)0x0)) &&
        (t_01 = tuple_prev_real_in_block(t), t_00 != (c2_tuple *)0x0)) &&
       (((t_01 != (c2_tuple *)0x0 && ((t_00->flags & 1) != 0)) &&
        (((t_01->flags & 1) != 0 &&
         ((t_00->dst != (c2_operand *)0x0 && (t_00->src != (c2_operand *)0x0)))))))) &&
      ((t_01->dst != (c2_operand *)0x0 &&
       ((((t_01->src != (c2_operand *)0x0 &&
          (iVar5 = operand_lists_equal(t_00->dst,t_01->dst), iVar5 != 0)) &&
         ((t_00->type & 0xf000) != 0x4000)) && ((t_01->type & 0xf000) != 0x4000)))))) &&
     ((((t_00->dst->kind != '\x06' && (t_00->src->kind != '\x06')) ||
       ((bVar4 = false, t_01->dst->kind != '\x06' && (t_01->src->kind != '\x06')))) &&
      ((((t_02 = tuple_prev_real_in_block(t_01), t_02 != (c2_tuple *)0x0 && (t_02->kind == '\x1a'))
        && (pcVar6 = tuple_prev_real_in_block(t_02), jmp == pcVar6)) &&
       ((((jcc = tuple_prev_real_in_block(t_00), jcc != (c2_tuple *)0x0 && (jcc->kind == '\x11')) &&
         ((jcc->u20).cond_cells != (c2_cond_cell *)0x0)) &&
        (pcVar1 = jcc->src, *(c2_tuple **)((int)&pcVar1->sym->u30 + 2) == t_02)))))))) {
    if (bVar4) {
      bVar4 = true;
      for (; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        for (pcVar2 = t_00->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          iVar5 = operands_may_alias(pcVar1,pcVar2);
          if (iVar5 != 0) {
            bVar4 = false;
          }
        }
      }
      if (bVar4) {
        pcVar1 = t_00->dst;
        do {
          if (pcVar1 == (c2_operand *)0x0) {
            branch_free(jmp);
            tuple_unlink(t_00);
            tuple_insert_before(jcc,t_00);
            branch_invert_condition(jcc);
            tuple_retarget(jcc,(c2_node *)t,0);
            return t;
          }
          for (pcVar2 = t_01->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            iVar5 = operands_may_alias(pcVar1,pcVar2);
            if (iVar5 != 0) {
              return (c2_tuple *)0x0;
            }
          }
          pcVar1 = pcVar1->next;
        } while( true );
      }
    }
    for (pcVar1 = jcc->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      for (pcVar2 = t_01->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        iVar5 = operands_may_alias(pcVar1,pcVar2);
        if (iVar5 != 0) {
          return (c2_tuple *)0x0;
        }
      }
    }
    if (((t_00->op != 0x34) || (pcVar1 = t_00->dst, pcVar1->kind != '\x01')) ||
       ((((pcVar2 = t_00->src, pcVar2->kind != '\x01' ||
          ((pcVar2->next->kind != '\x01' || ((pcVar1->u18).reg != (pcVar2->u18).reg)))) ||
         ((pcVar2->u18).reg != (pcVar2->next->u18).reg)) ||
        (((pcVar1->next->kind == '\x01' && (pcVar3 = pcVar1->next->sym, pcVar3->cls == '\x03')) &&
         (pcVar3->def != (c2_tuple *)0x0)))))) {
      for (pcVar1 = t_01->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        for (pcVar2 = t_00->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          iVar5 = operands_may_alias(pcVar1,pcVar2);
          if (iVar5 != 0) {
            return (c2_tuple *)0x0;
          }
        }
      }
    }
    pcVar1 = t_02->dst;
    while( true ) {
      if (pcVar1 == (c2_operand *)0x0) {
        branch_free(jmp);
        tuple_unlink(t_01);
        tuple_insert_before(jcc,t_01);
        tuple_unlink(t_00);
        tuple_insert_after(jcc,t_00);
        tuple_retarget(jcc,(c2_node *)t,0);
        return t;
      }
      if (pcVar1 != (c2_operand *)jcc) break;
      pcVar1 = pcVar1->next;
    }
  }
  return (c2_tuple *)0x0;
}

