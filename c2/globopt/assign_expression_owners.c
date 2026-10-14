void __fastcall assign_expression_owners(c2_function *fn)

{
  uint16_t uVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  c2_const_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_const_operand *pcVar7;
  int iVar8;
  c2_tuple *pcVar9;
  c2_operand *pcVar10;
  c2_tuple *t;
  uint32_t op;
  c2_operand *cmp_b;
  c2_operand *next_use;
  c2_tuple *first_tuple;
  
  t = fn->cfg->first->head;
  first_tuple = t;
  if (t != (c2_tuple *)0x0) {
    do {
      if ((t->flags & 1) != 0) {
        for (pcVar6 = t->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if ((1 << (pcVar6->kind & 0x1f) & 0x60U) != 0) {
            uVar1 = pcVar6->type;
            pcVar4 = operand_new_intconst(0x1004,pcVar6->tag,0);
            pcVar5 = cse_find_or_make(0x14c,uVar1,pcVar6->base,pcVar4);
            if ((pcVar4->flags & 0x10) == 0) {
              node_free((c2_node *)pcVar4);
            }
            (pcVar6->u18).reg = pcVar5;
          }
        }
        for (pcVar6 = t->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
          if ((1 << (pcVar6->kind & 0x1f) & 0x60U) != 0) {
            uVar1 = pcVar6->type;
            pcVar4 = operand_new_intconst(0x1004,pcVar6->tag,0);
            pcVar5 = cse_find_or_make(0x14c,uVar1,pcVar6->base,pcVar4);
            if ((pcVar4->flags & 0x10) == 0) {
              node_free((c2_node *)pcVar4);
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
            if (((1 << (t->dst->kind & 0x1f) & 6U) == 0) || (t->dst->sym->def == (c2_tuple *)0x0))
            break;
            pcVar9 = find_next_use_of_dst(t,&next_use);
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
            pcVar6 = tuple_replace_src(pcVar9,next_use,pcVar6);
            operand_set_type(pcVar6,uVar1);
            symbol_free_chain(pcVar5->storage);
          }
          else if (op == 0x17d) {
            number_compare_expression(t);
          }
          else {
            if (((op == 0x16e) && ((t->type & 0xf000) == 0x1000)) &&
               (pcVar6 = t->src->next, pcVar6->kind == '\a')) {
              uVar3 = (pcVar6->u18).lo;
              op = 0x16d;
              (pcVar6->u18).lo = -uVar3;
              pcVar6->tag = -(pcVar6->tag + (uint)(uVar3 != 0));
              t->op = 0x16d;
            }
            iVar8 = node_has_side_effects((c2_node *)t);
            if (iVar8 == 0) {
              pcVar6 = t->src;
              if (pcVar6 == (c2_operand *)0x0) {
switchD_10727c0b_caseD_2:
                pcVar6 = (c2_operand *)0x0;
switchD_10727d27_caseD_2:
                pcVar10 = (c2_operand *)0x0;
              }
              else {
                switch(*(undefined1 *)
                        ((int)assign_expression_owners_jump_table_6 + pcVar6->kind + 0xb)) {
                case 0:
                  if ((pcVar6->flags & 0x20) != 0) goto switchD_10727c0b_caseD_2;
                  break;
                case 2:
                  goto switchD_10727c0b_caseD_2;
                }
                pcVar10 = pcVar6->next;
                if (pcVar10 == (c2_operand *)0x0) goto switchD_10727d27_caseD_2;
                switch(*(undefined1 *)
                        ((int)assign_expression_owners_jump_table_7 + pcVar10->kind + 0xb)) {
                case 0:
                  if ((pcVar10->flags & 0x20) != 0) goto switchD_10727d27_caseD_2;
                  break;
                case 2:
                  goto switchD_10727d27_caseD_2;
                }
              }
              pcVar6 = operand_new_cse_sym(op,t->type,pcVar6,pcVar10);
              goto LAB_10727d41;
            }
          }
        }
        break;
      case '\r':
      case '\x0e':
      case '\x15':
switchD_10727da3_caseD_d:
        pcVar6 = t->dst;
        if (((pcVar6 != (c2_operand *)0x0) && ((1 << (pcVar6->kind & 0x1f) & 6U) != 0)) &&
           ((pcVar6->sym->def != (c2_tuple *)0x0 &&
            (find_next_use_of_dst(t,&next_use), (next_use->flags & 0x20) != 0)))) {
          cse_unlink_def(t);
        }
        break;
      case '\x10':
        pcVar9 = t->src->sym->def;
        pcVar6 = pcVar9->src;
        if (pcVar6 == (c2_operand *)0x0) {
switchD_10727aca_caseD_2:
          pcVar10 = (c2_operand *)0x0;
        }
        else {
          switch((&UNK_10727e17)[pcVar6->kind]) {
          case 0:
            if ((pcVar6->flags & 0x20) != 0) goto switchD_10727aca_caseD_2;
          case 1:
            pcVar10 = pcVar6;
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
        pcVar6 = t->src->next;
        if (pcVar6 == (c2_operand *)0x0) {
switchD_10727b26_caseD_2:
          pcVar6 = (c2_operand *)0x0;
        }
        else {
          switch(*(undefined1 *)((int)assign_expression_owners_jump_table_3 + pcVar6->kind + 0xb)) {
          case 0:
            if ((pcVar6->flags & 0x20) != 0) goto switchD_10727b26_caseD_2;
            break;
          case 2:
            goto switchD_10727b26_caseD_2;
          }
        }
        pcVar2 = pcVar6->next;
        if (pcVar2 == (c2_operand *)0x0) {
switchD_10727b50_caseD_2:
          assign_expression_owners_case_1
                    (pcVar9,(c2_operand *)0x0,t,pcVar6,cmp_b,pcVar10,next_use,first_tuple);
          return;
        }
        switch(*(undefined1 *)((int)assign_expression_owners_jump_table_4 + pcVar2->kind + 0xb)) {
        case 0:
          if ((pcVar2->flags & 0x20) != 0) goto switchD_10727b50_caseD_2;
        case 1:
          uVar1 = t->type;
          pcVar4 = operand_new_intconst(0x1004,(uint)pcVar9->type,0);
          pcVar7 = operand_new_intconst(0x1004,(uint)(t->u20).cc,0);
          pcVar5 = get_expression_symbol_n(399,uVar1,6,pcVar10,cmp_b,pcVar6,pcVar2,pcVar7,pcVar4);
          pcVar6 = operand_new_sym(0x14a,uVar1,pcVar5);
          break;
        case 2:
          goto switchD_10727b50_caseD_2;
        }
        goto LAB_10727d41;
      case '\x12':
        if (((((g_intrinsic_desc[(t->u20).intrinsic.id].flags & 0x20) == 0) ||
             (t->dst == (c2_operand *)0x0)) || ((t->dst->flags & 0x40) != 0)) ||
           ((g_opt_basic != 0 && ((t->type & 0xf000) == 0x4000)))) goto switchD_10727da3_caseD_d;
        pcVar5 = cse_hash_call_or_intrinsic(t);
        pcVar6 = operand_new_sym(0x14a,t->type,pcVar5);
LAB_10727d41:
        replace_dst_with_expression(pcVar6,t);
      }
      t = t->next;
    } while (t != (c2_tuple *)0x0);
    for (; first_tuple != (c2_tuple *)0x0; first_tuple = first_tuple->next) {
      if (first_tuple->op == 0x15b) {
        number_assignment(first_tuple,1);
      }
    }
  }
  build_expression_use_lists();
  return;
}

