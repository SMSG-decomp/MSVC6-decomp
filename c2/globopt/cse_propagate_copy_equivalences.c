void __fastcall cse_propagate_copy_equivalences(c2_tuple *t)

{
  uint16_t type;
  c2_operand *pcVar1;
  c2_cse_expr *pcVar2;
  c2_operand *b;
  c2_symbol *sym;
  ushort uVar3;
  int iVar4;
  uint32_t uVar5;
  int iVar6;
  c2_symbol *s;
  uint32_t uVar7;
  c2_operand *pcVar8;
  c2_operand *pcVar9;
  c2_tuple *t_00;
  c2_operand *b_00;
  c2_copy_link *local_14;
  
  if ((((t->flags & 0x20) == 0) && (uVar3 = t->type & 0xf000, uVar3 != 0x4000)) && (uVar3 != 0x5000)
     ) {
    pcVar1 = t->dst;
    if (t->op == 0x15b) {
      if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def == (c2_tuple *)0x0)) &&
         ((b = t->src, (1 << (b->kind & 0x1f) & 6U) != 0 &&
          (local_14 = (b->sym->u34).source_links, local_14 != (c2_copy_link *)0x0)))) {
        do {
          sym = local_14->copy;
          pcVar2 = (sym->u18).expr;
          if (((pcVar2 != (c2_cse_expr *)0x0) && (uVar5 = pcVar2->op, uVar5 != 0x15b)) &&
             ((uVar5 != 0x14c &&
              (((uVar5 != 0x165 && (sym->def == (c2_tuple *)0x0)) &&
               (uVar5 = bitset_test(g_cur_avail_set,sym->id), uVar5 != 0)))))) {
            pcVar8 = pcVar2->operands;
            pcVar9 = pcVar8->next;
            iVar4 = operand_compare(pcVar8,b);
            if (iVar4 == 0) {
              pcVar8 = pcVar1;
            }
            if (((pcVar9 != (c2_operand *)0x0) &&
                (iVar6 = operand_compare(pcVar9,b), b_00 = pcVar1, iVar6 == 0)) ||
               (b_00 = pcVar9, iVar4 == 0)) {
              type = pcVar2->type;
              uVar5 = pcVar2->op;
              s = cse_find_or_make(uVar5,type,pcVar8,b_00);
              link_expression_operands(s);
              if (((s->def != (c2_tuple *)0x0) ||
                  (uVar7 = bitset_test(g_cur_avail_set,s->id), uVar7 == 0)) && (sym != s)) {
                pcVar8 = operand_new_sym(0x14a,type,sym);
                pcVar9 = operand_new_sym(0x14a,type,s);
                t_00 = tuple_new(0x15b,type,pcVar9,pcVar8,tuple_insert_after,t);
                iVar4 = is_compare_branch_op(uVar5);
                if (iVar4 != 0) {
                  t_00->flags13 = '\x01';
                }
                t_00->flags = t_00->flags | 0x20;
                number_assignment(t_00,0);
              }
            }
          }
          local_14 = local_14->next_of_source;
        } while (local_14 != (c2_copy_link *)0x0);
        return;
      }
    }
    else if ((((pcVar1 != (c2_operand *)0x0) && ((1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
             (pcVar2 = (pcVar1->sym->u18).expr, pcVar2 != (c2_cse_expr *)0x0)) && (t->op != 400)) {
      pcVar1 = pcVar2->operands->next;
      if (pcVar1 == (c2_operand *)0x0) {
        pcVar1 = t->src;
        if ((1 << (pcVar1->kind & 0x1f) & 6U) != 0) {
          cse_record_copy_equivalence(t,pcVar2,pcVar1,pcVar1,pcVar1->next);
        }
      }
      else if (pcVar1->next == (c2_operand *)0x0) {
        iVar4 = operand_compare(t->src,t->src->next);
        pcVar1 = t->src;
        if (iVar4 == 0) {
          if ((1 << (pcVar1->kind & 0x1f) & 6U) != 0) {
            cse_record_copy_equivalence(t,pcVar2,pcVar1,pcVar1,pcVar1);
            return;
          }
        }
        else {
          if ((1 << (pcVar1->kind & 0x1f) & 6U) != 0) {
            cse_record_copy_equivalence(t,pcVar2,pcVar1,pcVar1,pcVar1->next);
          }
          pcVar1 = t->src->next;
          if ((1 << (pcVar1->kind & 0x1f) & 6U) != 0) {
            cse_record_copy_equivalence(t,pcVar2,pcVar1,t->src,pcVar1);
            return;
          }
        }
      }
    }
  }
  return;
}

