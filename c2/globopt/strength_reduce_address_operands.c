void __fastcall strength_reduce_address_operands(c2_loop *loop)

{
  c2_symbol *pcVar1;
  c2_cse_expr *pcVar2;
  c2_symbol *sym;
  bool bVar3;
  c2_tuple *pcVar4;
  c2_list_cell *pcVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  uint32_t uVar8;
  c2_tuple *pcVar9;
  c2_operand *pcVar10;
  c2_operand *pcVar11;
  c2_operand *pcVar12;
  int iVar13;
  uint32_t uVar14;
  c2_tuple *local_28;
  c2_tuple *local_1c;
  c2_tuple *local_8;
  c2_operand *local_4;
  
  reset_iv_worklists();
  free_pending_tuple_list();
  collect_iv_candidates(loop,6);
  pcVar4 = iv_worklist_pop();
  while (pcVar4 != (c2_tuple *)0x0) {
    pcVar1 = pcVar4->dst->sym;
    pcVar2 = (pcVar1->u18).expr;
    pcVar12 = pcVar2->operands;
    sym = pcVar12->sym;
    if (sym->uses != (c2_list_cell *)0x0) {
      pcVar7 = iv_find_copy_source(pcVar12->next,loop);
      uVar8 = map_iv_update_opcode(pcVar2->op);
      bVar3 = true;
      pcVar5 = pcVar1->uses;
      local_28 = (c2_tuple *)0x0;
      local_1c = (c2_tuple *)0x0;
      if (pcVar5 != (c2_list_cell *)0x0) {
        do {
          if (!bVar3) break;
          pcVar9 = (pcVar5->u04).tuple;
          if (pcVar9->flags13 != '\x04') {
            if (((pcVar9->op == 0x15b) && ((1 << (pcVar9->src->kind & 0x1f) & 6U) != 0)) &&
               (pcVar9->src->sym == pcVar1)) {
              if ((local_28 != (c2_tuple *)0x0) ||
                 (local_28 = pcVar9, ((sym->u30).sizeopt.width_facts & 1) != 0)) {
                bVar3 = false;
                local_28 = pcVar9;
              }
            }
            else if (pcVar9->op == 0x17d) {
              pcVar10 = pcVar9->src;
              uVar14 = is_loop_invariant_operand(pcVar10->next);
              if ((uVar14 == 0) ||
                 ((((pcVar6 = sr_materialize_operand_in_preheader(pcVar9->src->next,loop),
                    pcVar6->kind != '\a' || (pcVar7->kind != '\a')) ||
                   (iVar13 = sr_combine_allowed(pcVar6,pcVar7,uVar8), iVar13 == 0)) &&
                  (((uVar8 != 0x16d || (pcVar6->kind != '\x03')) ||
                   ((pcVar7->kind != '\x03' || (pcVar6->sym->storage != pcVar7->sym->storage))))))))
              {
                if (((1 << (pcVar10->kind & 0x1f) & 6U) == 0) || (pcVar10->sym != pcVar1))
                goto LAB_10747704;
                if ((local_1c != (c2_tuple *)0x0) ||
                   (local_1c = pcVar9, ((sym->u30).sizeopt.width_facts & 1) != 0)) {
                  bVar3 = false;
                  local_1c = pcVar9;
                }
              }
            }
            else {
LAB_10747704:
              if ((pcVar9->type & 0xf000) == 0x5000) {
                bVar3 = false;
                break;
              }
              if ((pcVar9->op == 0x16d) && ((pcVar9->type & 0xfff) == 4)) {
                pcVar10 = pcVar9->src;
                for (pcVar6 = pcVar10; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
                  if ((((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym == pcVar1)) &&
                     ((pcVar6->flags & 0x20) == 0)) {
                    if (pcVar10 == pcVar6) {
                      pcVar10 = pcVar10->next;
                    }
                    pcVar11 = sr_make_address_operand(pcVar10,pcVar6);
                    if (pcVar11 != (c2_operand *)0x0) {
                      pcVar9->op = 0x167;
                      tuple_remove_src(pcVar9,pcVar6);
                      tuple_replace_src(pcVar9,pcVar10,pcVar11);
                    }
                    break;
                  }
                }
              }
              for (pcVar10 = pcVar9->src; pcVar10 != (c2_operand *)0x0; pcVar10 = pcVar10->next) {
                if (((1 << (pcVar10->kind & 0x1f) & 6U) != 0) && (pcVar10->sym == pcVar1)) {
                  if ((pcVar10->flags & 0x20) != 0) {
                    pcVar6 = find_mem_operand_using(pcVar9,pcVar10,&local_4);
                    iVar13 = sr_fold_into_address_mode(pcVar9,pcVar6,pcVar10,uVar8,pcVar12,pcVar7,0)
                    ;
                    if (iVar13 != 0) goto LAB_10747823;
                  }
                  bVar3 = false;
                }
LAB_10747823:
              }
            }
          }
          pcVar5 = pcVar5->next;
        } while (pcVar5 != (c2_list_cell *)0x0);
        if (((local_1c != (c2_tuple *)0x0) &&
            (((local_28 == (c2_tuple *)0x0 || (local_1c->prev != local_28)) ||
             (iVar13 = operand_compare(local_28->src,local_1c->src), iVar13 != 0)))) || (!bVar3)) {
          sr_materialize_iv_address_uses(pcVar1);
          goto LAB_107478a1;
        }
      }
      pcVar9 = symbol_pop_use(pcVar1);
      while (pcVar9 != (c2_tuple *)0x0) {
        if (pcVar9->flags13 == '\x04') {
          symbol_remove_def(pcVar1,pcVar9->next);
          tuple_unlink_free(pcVar9->next);
          tuple_unlink_free(pcVar9);
        }
        else if (((pcVar9->op == 0x15b) &&
                 (pcVar10 = pcVar9->src, (1 << (pcVar10->kind & 0x1f) & 6U) != 0)) &&
                (pcVar10->sym == pcVar1)) {
          local_8 = tuple_new_cse_binary
                              (uVar8,local_28->type,pcVar12,pcVar7,tuple_insert_before,local_28);
          tuple_replace_src(local_28,pcVar10,local_8->dst);
          add_symbol_loop_use(sym,local_8);
          iv_retry_list_push(local_28);
        }
        else if (pcVar9->op == 0x17d) {
          if (local_1c == (c2_tuple *)0x0) {
            pcVar10 = sr_materialize_operand_in_preheader(pcVar9->src->next,loop);
            sr_fold_constant_pair(pcVar9,pcVar10,pcVar7,uVar8,pcVar12);
          }
          else {
            tuple_replace_src(local_1c,pcVar9->src,local_28->dst);
            uVar14 = is_induction_variable_operand(local_28->dst);
            if (uVar14 != 0) {
              add_symbol_loop_use(local_28->dst->sym,local_8);
            }
            iv_retry_list_push(local_1c);
          }
        }
        else {
          pcVar10 = pcVar9->src;
          while (pcVar6 = pcVar10, pcVar6 != (c2_operand *)0x0) {
            pcVar10 = pcVar6->next;
            if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym == pcVar1)) {
              pcVar11 = find_mem_operand_using(pcVar9,pcVar6,&local_4);
              sr_fold_into_address_mode(pcVar9,pcVar11,pcVar6,uVar8,pcVar12,pcVar7,1);
              iv_retry_list_push(pcVar9);
            }
          }
        }
        pcVar9 = symbol_pop_use(pcVar1);
      }
      tuple_delete_if_dead((c2_node *)pcVar4,1);
      if (((pcVar7->kind == '\x02') && (pcVar1 = pcVar7->sym, pcVar1 != (c2_symbol *)0x0)) &&
         ((((pcVar1->u30).sizeopt.width_facts & 2) != 0 ||
          (uVar8 = bitset_test(g_hoisted_exprs,pcVar1->id), uVar8 != 0)))) {
        sr_hoist_invariant_operand(pcVar7,loop);
      }
    }
LAB_107478a1:
    pcVar4 = iv_worklist_pop();
  }
  pcVar4 = iv_retry_list_pop();
  do {
    if (pcVar4 == (c2_tuple *)0x0) {
      recompute_loop_liveness(loop,1);
      free_pending_tuple_list();
      return;
    }
    tuple_unlink_mem_subops(pcVar4);
    switch(pcVar4->op) {
    case 0x15b:
      pcVar12 = pcVar4->dst;
      if ((1 << (pcVar12->kind & 0x1f) & 0x60U) != 0) {
        pcVar7 = pcVar12->index;
        if (((pcVar12->base != (c2_operand *)0x0) &&
            (uVar8 = is_induction_variable_operand(pcVar12->base), uVar8 != 0)) ||
           ((pcVar7 != (c2_operand *)0x0 &&
            (uVar8 = is_induction_variable_operand(pcVar7), uVar8 != 0)))) {
          pcVar7 = materialize_memory_address(pcVar4,pcVar12);
          pcVar12->op = 0x14c;
          pcVar7->flags = pcVar7->flags | 0x20;
          pcVar12->base_sym = (c2_symbol *)0x0;
          if (pcVar12->base != (c2_operand *)0x0) {
            node_free((c2_node *)pcVar12->base);
          }
          pcVar7 = operand_claim(pcVar7);
          pcVar12->base = pcVar7;
          if (pcVar12->index != (c2_operand *)0x0) {
            node_free((c2_node *)pcVar12->index);
          }
          pcVar12->index = (c2_operand *)0x0;
          pcVar12->disp = 0;
          pcVar12->flags = pcVar12->flags & 0xf0;
        }
      }
      if ((1 << (pcVar4->src->kind & 0x1f) & 0x60U) != 0) goto switchD_10747c48_caseD_15d;
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0x2110);
    case 0x15d:
switchD_10747c48_caseD_15d:
      pcVar12 = pcVar4->src;
      pcVar7 = pcVar12->index;
      if (((pcVar12->base != (c2_operand *)0x0) &&
          (uVar8 = is_induction_variable_operand(pcVar12->base), uVar8 != 0)) ||
         ((pcVar7 != (c2_operand *)0x0 &&
          (uVar8 = is_induction_variable_operand(pcVar7), uVar8 != 0)))) {
        pcVar7 = materialize_memory_address(pcVar4,pcVar12);
        pcVar12->op = 0x14c;
        pcVar7->flags = pcVar7->flags | 0x20;
        pcVar12->base_sym = (c2_symbol *)0x0;
        if (pcVar12->base != (c2_operand *)0x0) {
          node_free((c2_node *)pcVar12->base);
        }
        pcVar7 = operand_claim(pcVar7);
        pcVar12->base = pcVar7;
        if (pcVar12->index != (c2_operand *)0x0) {
          node_free((c2_node *)pcVar12->index);
        }
        pcVar12->index = (c2_operand *)0x0;
        pcVar12->disp = 0;
        pcVar12->flags = pcVar12->flags & 0xf0;
      }
      break;
    case 0x167:
      pcVar12 = materialize_memory_address(pcVar4,pcVar4->src);
      tuple_replace_src(pcVar4,pcVar4->src,pcVar12);
      pcVar4->op = 0x15b;
      break;
    case 0x17d:
      break;
    }
    tuple_relink_mem_subops(pcVar4);
    enter_tuple_in_expression_table(pcVar4,0);
    pcVar4 = iv_retry_list_pop();
  } while( true );
}

