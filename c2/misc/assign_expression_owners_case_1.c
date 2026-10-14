void assign_expression_owners_case_1
               (c2_tuple *cmp_def,c2_operand *val_b,c2_tuple *t,c2_operand *val_a,c2_operand *cmp_b,
               c2_operand *cmp_a,c2_operand *next_use,c2_tuple *first_tuple)

{
  uint16_t uVar1;
  uint32_t uVar2;
  c2_const_operand *pcVar3;
  c2_const_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  int iVar7;
  c2_tuple *pcVar8;
  c2_operand *b;
  uint32_t op;
  
code_r0x10727b57:
  uVar1 = t->type;
  pcVar3 = operand_new_intconst(0x1004,(uint)cmp_def->type,0);
  pcVar4 = operand_new_intconst(0x1004,(uint)(t->u20).cc,0);
  pcVar5 = get_expression_symbol_n(399,uVar1,6,cmp_a,cmp_b,val_a,val_b,pcVar4,pcVar3);
  pcVar6 = operand_new_sym(0x14a,uVar1,pcVar5);
LAB_10727d41:
  replace_dst_with_expression(pcVar6,t);
switchD_10727da3_caseD_f:
  do {
    t = t->next;
    pcVar8 = first_tuple;
    if (t == (c2_tuple *)0x0) {
      for (; pcVar8 != (c2_tuple *)0x0; pcVar8 = pcVar8->next) {
        if (pcVar8->op == 0x15b) {
          number_assignment(pcVar8,1);
        }
      }
      build_expression_use_lists();
      return;
    }
    if ((t->flags & 1) != 0) {
      for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
        if ((1 << (pcVar6->kind & 0x1f) & 0x60U) != 0) {
          uVar1 = pcVar6->type;
          pcVar3 = operand_new_intconst(0x1004,pcVar6->tag,0);
          pcVar5 = cse_find_or_make(0x14c,uVar1,pcVar6->base,pcVar3);
          if ((pcVar3->flags & 0x10) == 0) {
            node_free((c2_node *)pcVar3);
          }
          (pcVar6->u18).reg = pcVar5;
        }
      }
      for (pcVar6 = t->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
        if ((1 << (pcVar6->kind & 0x1f) & 0x60U) != 0) {
          uVar1 = pcVar6->type;
          pcVar3 = operand_new_intconst(0x1004,pcVar6->tag,0);
          pcVar5 = cse_find_or_make(0x14c,uVar1,pcVar6->base,pcVar3);
          if ((pcVar3->flags & 0x10) == 0) {
            node_free((c2_node *)pcVar3);
          }
          (pcVar6->u18).reg = pcVar5;
        }
      }
    }
    switch(t->kind) {
    case '\f':
      op = t->op;
      if (op != 0x15a) {
        if (op == 0x15b) {
          if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) {
            pcVar8 = find_next_use_of_dst(t,&next_use);
            pcVar6 = t->src;
            if (pcVar6 == (c2_operand *)0x0) {
switchD_10727c62_caseD_2:
              pcVar6 = (c2_operand *)0x0;
            }
            else {
              switch(*(undefined1 *)
                      ((int)assign_expression_owners_jump_table_5 + pcVar6->kind + 0xb)) {
              case 0:
                if ((pcVar6->flags & 0x20) != 0) goto switchD_10727c62_caseD_2;
                break;
              case 2:
                goto switchD_10727c62_caseD_2;
              }
            }
            pcVar6 = operand_new_cse_sym(0x165,t->type,pcVar6,(c2_operand *)0x0);
            pcVar5 = t->dst->sym;
            tuple_replace_dst(t,t->dst,pcVar6);
            uVar1 = next_use->type;
            pcVar6 = tuple_replace_src(pcVar8,next_use,pcVar6);
            operand_set_type(pcVar6,uVar1);
            symbol_free_chain(pcVar5->storage);
          }
        }
        else {
          if (op != 0x17d) goto code_r0x10727bd3;
          number_compare_expression(t);
        }
      }
      break;
    case '\x10':
      cmp_def = t->src->sym->def;
      pcVar6 = cmp_def->src;
      if (pcVar6 == (c2_operand *)0x0) {
switchD_10727aca_caseD_2:
        cmp_a = (c2_operand *)0x0;
      }
      else {
        switch((&UNK_10727e17)[pcVar6->kind]) {
        case 0:
          if ((pcVar6->flags & 0x20) != 0) goto switchD_10727aca_caseD_2;
        case 1:
          cmp_a = pcVar6;
          break;
        case 2:
          goto switchD_10727aca_caseD_2;
        }
      }
      cmp_b = pcVar6->next;
      if (cmp_b == (c2_operand *)0x0) {
switchD_10727af9_caseD_2:
        cmp_b = (c2_operand *)0x0;
      }
      else {
        switch(*(undefined1 *)((int)assign_expression_owners_jump_table_2 + cmp_b->kind + 0xb)) {
        case 0:
          if ((cmp_b->flags & 0x20) != 0) goto switchD_10727af9_caseD_2;
        case 1:
          break;
        case 2:
          goto switchD_10727af9_caseD_2;
        }
      }
      val_a = t->src->next;
      if (val_a == (c2_operand *)0x0) {
switchD_10727b26_caseD_2:
        val_a = (c2_operand *)0x0;
      }
      else {
        switch(*(undefined1 *)((int)assign_expression_owners_jump_table_3 + val_a->kind + 0xb)) {
        case 0:
          if ((val_a->flags & 0x20) != 0) goto switchD_10727b26_caseD_2;
          break;
        case 2:
          goto switchD_10727b26_caseD_2;
        }
      }
      val_b = val_a->next;
      if (val_b != (c2_operand *)0x0) {
        switch(*(undefined1 *)((int)assign_expression_owners_jump_table_4 + val_b->kind + 0xb)) {
        case 0:
          if ((val_b->flags & 0x20) == 0) goto code_r0x10727b57;
          break;
        case 1:
          goto code_r0x10727b57;
        }
      }
      assign_expression_owners_case_1
                (cmp_def,(c2_operand *)0x0,t,val_a,cmp_b,cmp_a,next_use,first_tuple);
      return;
    case '\x12':
      if (((((g_intrinsic_desc[(t->u20).intrinsic.id].flags & 0x20) != 0) &&
           (t->dst != (c2_operand *)0x0)) && ((t->dst->flags & 0x40) == 0)) &&
         ((g_opt_basic == 0 || ((t->type & 0xf000) != 0x4000)))) {
        pcVar5 = cse_hash_call_or_intrinsic(t);
        pcVar6 = operand_new_sym(0x14a,t->type,pcVar5);
        goto LAB_10727d41;
      }
    case '\r':
    case '\x0e':
    case '\x15':
      pcVar6 = t->dst;
      if (((pcVar6 != (c2_operand *)0x0) && ((1 << (pcVar6->kind & 0x1f) & 6U) != 0)) &&
         ((pcVar6->sym->def != (c2_tuple *)0x0 &&
          (find_next_use_of_dst(t,&next_use), (next_use->flags & 0x20) != 0)))) {
        cse_unlink_def(t);
      }
    }
  } while( true );
code_r0x10727bd3:
  if (((op == 0x16e) && ((t->type & 0xf000) == 0x1000)) &&
     (pcVar6 = t->src->next, pcVar6->kind == '\a')) {
    uVar2 = (pcVar6->u18).lo;
    op = 0x16d;
    (pcVar6->u18).lo = -uVar2;
    pcVar6->tag = -(pcVar6->tag + (uint)(uVar2 != 0));
    t->op = 0x16d;
  }
  iVar7 = node_has_side_effects((c2_node *)t);
  if (iVar7 == 0) goto code_r0x10727bee;
  goto switchD_10727da3_caseD_f;
code_r0x10727bee:
  pcVar6 = t->src;
  if (pcVar6 == (c2_operand *)0x0) {
switchD_10727c0b_caseD_2:
    pcVar6 = (c2_operand *)0x0;
  }
  else {
    switch(*(undefined1 *)((int)assign_expression_owners_jump_table_6 + pcVar6->kind + 0xb)) {
    case 0:
      if ((pcVar6->flags & 0x20) != 0) goto switchD_10727c0b_caseD_2;
      break;
    case 2:
      goto switchD_10727c0b_caseD_2;
    }
    b = pcVar6->next;
    if (b != (c2_operand *)0x0) {
      switch(*(undefined1 *)((int)assign_expression_owners_jump_table_7 + b->kind + 0xb)) {
      case 0:
        if ((b->flags & 0x20) == 0) goto switchD_10727d27_caseD_1;
        break;
      case 1:
        goto switchD_10727d27_caseD_1;
      }
    }
  }
  b = (c2_operand *)0x0;
switchD_10727d27_caseD_1:
  pcVar6 = operand_new_cse_sym(op,t->type,pcVar6,b);
  goto LAB_10727d41;
}

