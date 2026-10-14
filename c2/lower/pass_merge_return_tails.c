void __fastcall pass_merge_return_tails(c2_function *fn)

{
  c2_operand *op;
  c2_tuple *pcVar1;
  c2_tuple *other_jump;
  c2_tuple *pcVar2;
  c2_operand **ppcVar3;
  int iVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  c2_fe_symbol *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *pcVar9;
  c2_operand *b;
  c2_tuple *skip;
  c2_operand *local_24;
  c2_label_ref *other_ref;
  int local_1c;
  c2_tuple *local_18;
  c2_label_ref *ref;
  
  if (g_opt_favor_speed == 0) {
    pcVar2 = fn->cfg->last->end->prev;
    do {
      pcVar2 = pcVar2->prev;
      if (pcVar2 == (c2_tuple *)0x0) {
        return;
      }
      if ((pcVar2->flags & 1) != 0) {
        return;
      }
    } while (pcVar2->kind != '\x1a');
    ref = (c2_label_ref *)pcVar2->dst;
    if (ref != (c2_label_ref *)0x0) {
      other_jump = tuple_prev_real(pcVar2);
      if (other_jump->kind == '\x0f') {
        if (other_jump->line != 0) {
          g_current_line_abs = fn->line_base + (uint)other_jump->line;
          g_cur_line = other_jump->line;
        }
        tuple_new_branch(0x186,'\0',(c2_node *)pcVar2,(c2_operand *)0x0,(c2_tuple *)0x0,
                         tuple_insert_after,other_jump);
        ref = (c2_label_ref *)pcVar2->dst;
      }
      for (; (c2_operand *)ref != (c2_operand *)0x0; ref = (c2_label_ref *)((c2_operand *)ref)->next
          ) {
        pcVar2 = (c2_tuple *)((c2_operand *)ref)->rank;
        if (pcVar2->op == 0x186) {
          do {
            pcVar2 = pcVar2->prev;
          } while ((pcVar2->flags & 1) == 0);
          if (pcVar2->kind == '\x0f') {
            ppcVar3 = &pcVar2->src;
            local_24 = *ppcVar3;
            if ((((1 << (local_24->kind & 0x1f) & 6U) == 0) ||
                (local_24->sym->def == (c2_tuple *)0x0)) && (local_24->kind != 6)) {
              other_ref = (c2_label_ref *)((c2_operand *)ref)->next;
              b = (c2_operand *)0x0;
              if ((c2_operand *)other_ref != (c2_operand *)0x0) {
                while (other_jump = (c2_tuple *)other_ref->referrer, pcVar8 = other_jump,
                      other_jump->op == 0x186) {
                  do {
                    pcVar8 = pcVar8->prev;
                  } while ((pcVar8->flags & 1) == 0);
                  if (pcVar8->kind != '\x0f') break;
                  op = pcVar8->src;
                  if ((((1 << (op->kind & 0x1f) & 6U) != 0) && (op->sym->def != (c2_tuple *)0x0)) ||
                     ((op->kind == 6 ||
                      (iVar4 = compare_trees((c2_node *)pcVar2,(c2_node *)pcVar8), iVar4 == 0))))
                  break;
                  skip = (c2_tuple *)0x0;
                  local_1c = 0;
                  local_18 = (c2_tuple *)0x0;
                  pcVar9 = pcVar8;
                  pcVar6 = pcVar2;
                  while( true ) {
                    pcVar9 = pcVar9->prev;
                    pcVar6 = pcVar6->prev;
                    if ((pcVar9->flags & 1) == 0) break;
                    if (((pcVar6->kind == '\x1a') && (*(char *)&pcVar6->src[1].next == 'Y')) &&
                       ((pcVar1 = pcVar6->prev, pcVar6 = pcVar1, pcVar1->op == 0x15b &&
                        (iVar4 = operand_compare(pcVar1->dst,b), iVar4 == 0)))) {
                      local_24 = pcVar1->src;
                      pcVar6 = pcVar1->prev;
                      skip = pcVar1;
                      local_18 = pcVar1;
                    }
                    if (((((pcVar6->flags & 1) == 0) ||
                         (iVar4 = merge_tails_tree_compare((c2_node *)pcVar6,(c2_node *)pcVar9),
                         iVar4 != 0)) ||
                        (iVar4 = range_dst_may_alias(pcVar6,&pcVar6->next,local_24), iVar4 != 0)) ||
                       (iVar4 = range_dst_may_alias(pcVar9,&pcVar9->next,op), iVar4 != 0)) break;
                    local_1c = local_1c + 1;
                  }
                  if ((local_1c != 0) &&
                     (uVar5 = dbcheck_sequence_defs_local(pcVar6->next,pcVar2->prev), uVar5 != 0)) {
                    merge_alias_annotations
                              (pcVar6->next,pcVar2->prev,pcVar9->next,pcVar8->prev,skip);
                    pcVar8 = pcVar6->next;
                    if (b == (c2_operand *)0x0) {
                      b = operand_new_temp_sym(pcVar2->type);
                      g_cur_line = 0;
                      pcVar6 = tuple_new(0x15b,b->type,b,local_24,tuple_insert_before,pcVar8);
                      pcVar7 = label_symbol_new();
                      pcVar8 = tuple_new_label(pcVar7);
                      *(undefined1 *)&pcVar8->src[1].next = 0x59;
                      tuple_insert_after(pcVar6,pcVar8);
                      tuple_replace_src(pcVar2,*ppcVar3,b);
                    }
                    else if ((skip == (c2_tuple *)0x0) || (skip == pcVar8)) {
                      if (pcVar8->kind != '\x1a') {
                        if (pcVar8 == skip) {
                          pcVar8 = pcVar8->next;
                        }
                        else {
                          pcVar7 = label_symbol_new();
                          pcVar6 = tuple_new_label(pcVar7);
                          *(undefined1 *)&pcVar6->src[1].next = 0x59;
                          tuple_insert_before(pcVar8,pcVar6);
                          pcVar8 = pcVar6;
                        }
                      }
                    }
                    else {
                      tuple_move_before(pcVar8,skip);
                      pcVar7 = label_symbol_new();
                      pcVar8 = tuple_new_label(pcVar7);
                      *(undefined1 *)&pcVar8->src[1].next = 0x59;
                      tuple_insert_after(local_18,pcVar8);
                    }
                    if (pcVar9->line != 0) {
                      g_current_line_abs = fn->line_base + (uint)pcVar9->line;
                      g_cur_line = pcVar9->line;
                    }
                    pcVar9 = tuple_new(0x15b,b->type,b,op,tuple_insert_after,pcVar9);
                    pcVar8 = tuple_new_jmp_before(pcVar8,pcVar9->next);
                    tuple_range_free(pcVar8->next,other_jump->next);
                    local_24 = *ppcVar3;
                    other_ref = ref;
                  }
                  other_ref = other_ref->next;
                  if (other_ref == (c2_label_ref *)0x0) break;
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}

