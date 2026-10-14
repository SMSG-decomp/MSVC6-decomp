void __fastcall rewrite_loop_guard_compare(c2_loop *loop)

{
  c2_symbol *b;
  c2_tuple *t;
  c2_operand *a;
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  uint32_t uVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_operand *op;
  c2_block *pcVar7;
  
  pcVar1 = tuple_prev_real_before_boundary(loop->guard->end);
  if ((((pcVar1 != (c2_tuple *)0x0) && (pcVar1->kind == '\x11')) &&
      (((pcVar1->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar1->op == 0x18b)))) &&
     (((((((pcVar1->flags & 8) == 0 &&
          (pcVar1 = pcVar1->src->next->sym->def, pcVar1 != (c2_tuple *)0x0)) &&
         (pcVar1->op == 0x17d)) &&
        ((pcVar2 = tuple_prev_real_before_boundary(loop->last->end), pcVar2 != (c2_tuple *)0x0 &&
         (pcVar2->kind == '\x11')))) &&
       (((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar2->op == 0x18b)))) &&
      (((pcVar2 = pcVar2->src->next->sym->def, pcVar2 != (c2_tuple *)0x0 && (pcVar2->op == 0x17d))
       && (iVar3 = types_compatible(pcVar1->type,0x1008), iVar3 != 0)))))) {
    op = (c2_operand *)0x0;
    g_cur_avail_set = loop->guard->set54;
    pcVar6 = pcVar1->src;
    do {
      do {
        a = pcVar6;
        if (a == (c2_operand *)0x0) goto LAB_10748363;
        pcVar6 = a->next;
      } while ((a->kind != '\a') || ((a->u18).reg == (c2_symbol *)0x0 && a->tag == 0));
      uVar4 = bitset_iter_next(g_cur_avail_set);
      while (uVar4 != 0xffffffff) {
        pcVar5 = symbol_by_id(uVar4);
        if (((pcVar5->u18).expr)->op == 0x15b) {
          op = ((pcVar5->u18).expr)->operands;
          if ((((op->kind == '\x02') && (iVar3 = operand_compare(a,op->next), iVar3 == 0)) &&
              (uVar4 = operand_live_out_of_preheader(op), uVar4 != 0)) &&
             ((iVar3 = operand_compare(op,pcVar2->src), iVar3 == 0 ||
              (iVar3 = operand_compare(op,pcVar2->src->next), iVar3 == 0)))) break;
          op = (c2_operand *)0x0;
        }
        uVar4 = bitset_iter_next((c2_bitset *)0x0);
      }
    } while (op == (c2_operand *)0x0);
    pcVar6 = tuple_replace_src(pcVar1,a,op);
    enter_tuple_in_expression_table(pcVar1,0);
    pcVar6->flags9 = pcVar6->flags9 | 8;
  }
LAB_10748363:
  if (g_iv_syms->chunks != (c2_bitset_chunk *)0x0) {
    g_cur_avail_set = sparse_set_alloc_default();
    pcVar1 = loop->preheader->end;
    pcVar2 = loop->preheader->head->next;
    while (t = pcVar2, t != pcVar1) {
      pcVar2 = t->next;
      if (t->op == 0x15b) {
        pcVar6 = t->dst;
        uVar4 = is_loop_invariant_operand(pcVar6);
        if (uVar4 != 0) {
          if (t->src->kind == '\a') {
            avail_transfer_tuple(t);
          }
          else {
            bitset_set(loop->invariant_syms,pcVar6->sym->id);
          }
        }
      }
    }
    pcVar7 = loop->first;
    if (pcVar7 != loop->last->next) {
      do {
        pcVar1 = pcVar7->head->next;
        if (pcVar1 != pcVar7->end) {
          do {
            if ((pcVar1->flags & 1) != 0) {
              cse_replace_operands(pcVar1);
            }
            pcVar1 = pcVar1->next;
          } while (pcVar1 != pcVar7->end);
        }
        pcVar7 = pcVar7->next;
      } while (pcVar7 != loop->last->next);
    }
    pcVar7 = loop->first;
    if (pcVar7 != loop->last->next) {
      do {
        pcVar1 = pcVar7->head->next;
        if (pcVar1 != pcVar7->end) {
          do {
            if (((pcVar1->op == 0x15b) && (pcVar1->dst->kind == '\x02')) &&
               ((pcVar1->src->kind == '\x02' &&
                (pcVar5 = pcVar1->src->sym, ((pcVar5->u30).sizeopt.width_facts & 1) != 0)))) {
              b = pcVar1->dst->sym;
              if (((b->u30).sizeopt.width_facts & 1) == 0) {
                if ((b->u18).expr != (c2_cse_expr *)0x0) {
                  cse_add_copy_link(pcVar5,b);
                }
              }
              else {
                b->flags7 = b->flags7 | 2;
              }
            }
            if (pcVar1->flags13 == '\x04') {
              enter_tuple_in_expression_table(pcVar1,1);
              pcVar1->flags13 = '\0';
            }
            else if ((pcVar1->op == 0x15b) && ((pcVar1->u14).arg == (void *)0x0)) {
              enter_tuple_in_expression_table(pcVar1,1);
            }
            pcVar1 = pcVar1->next;
          } while (pcVar1 != pcVar7->end);
        }
        pcVar7 = pcVar7->next;
      } while (pcVar7 != loop->last->next);
    }
  }
  return;
}

