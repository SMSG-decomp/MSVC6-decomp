int __fastcall jump_optimize_sweep(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *label;
  c2_operand *pcVar2;
  uint32_t uVar3;
  int iVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  uint uVar7;
  c2_tuple *local_8;
  int local_4;
  
  local_4 = 0;
  pcVar1 = fn->cfg->last->end;
  pcVar6 = fn->cfg->first->head->next;
  if (pcVar6 == pcVar1) {
    return 0;
  }
  do {
    local_8 = pcVar6->next;
    switch(pcVar6->kind) {
    case '\x0f':
    case '\x13':
      uVar3 = delete_unreachable_after(fn,pcVar6);
LAB_10737814:
      if (uVar3 != 0) {
LAB_1073781c:
        uVar7 = 1;
        local_8 = pcVar6;
LAB_1073788d:
        local_4 = local_4 + uVar7;
        local_8 = jump_opt_restart_point(local_8);
      }
      break;
    case '\x11':
      if ((((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0) && (pcVar6->op != 0x18b)) &&
         (iVar4 = delete_unreachable_after(fn,pcVar6), iVar4 != 0)) goto LAB_1073781c;
      if (((pcVar6->src->kind == '\x04') && (*(int *)((int)&pcVar6->src->sym->u30 + 2) != 0)) &&
         ((pcVar6->flags & 8) == 0)) {
        iVar4 = delete_jump_to_next(pcVar6,&local_8);
        if (iVar4 == 0) {
          uVar3 = jump_opt_target_is_18c(pcVar6);
          if (uVar3 == 0) {
            if (g_opt_global != 0) {
              if (((pcVar6->u20).cond_cells != (c2_cond_cell *)0x0) || (pcVar6->op == 0x18b)) {
                if (pcVar6->line != 0) {
                  g_current_line_abs = fn->line_base + (uint)pcVar6->line;
                  g_cur_line = pcVar6->line;
                }
                pcVar5 = delete_redundant_cond_branch(pcVar6);
                if (pcVar5 != (c2_tuple *)0x0) {
                  uVar7 = 1;
                  local_8 = pcVar5;
                  goto LAB_1073788d;
                }
                iVar4 = invert_branch_over_jump(pcVar6);
                if ((iVar4 == 0) && (uVar3 = thread_cond_branch_by_implication(pcVar6), uVar3 == 0))
                {
                  if (g_jumpopt_no_crossjump == 0) {
                    iVar4 = hoist_common_successor_heads(pcVar6);
                    if (iVar4 != 0) {
                      uVar7 = 1;
                      goto LAB_1073788d;
                    }
                    uVar3 = cross_jump_complementary_branches((c2_tuple *)fn,pcVar6);
                    if (uVar3 != 0) goto LAB_1073781c;
                    pcVar5 = tuple_prev_real(pcVar6);
                    uVar3 = pcVar5->op;
                    if (((uVar3 == 0x2f) || (uVar3 == 0x33)) || (uVar3 == 0x30)) {
                      uVar3 = eliminate_redundant_compare_across_branch(pcVar5,pcVar6);
                      goto LAB_10737814;
                    }
                  }
                  break;
                }
                goto LAB_1073781c;
              }
              if (g_jumpopt_no_crossjump == 0) {
                iVar4 = cross_jump_into_fallthrough(pcVar6);
                if (iVar4 != 0) {
                  local_8 = pcVar6;
                }
                uVar7 = (uint)(iVar4 != 0);
                pcVar6 = hoist_join_instruction(pcVar6);
                if (pcVar6 != (c2_tuple *)0x0) {
                  uVar7 = uVar7 + 1;
                  local_8 = pcVar6;
                }
                if (uVar7 != 0) goto LAB_1073788d;
              }
            }
            break;
          }
          uVar7 = 1;
        }
        else {
          uVar7 = 1;
        }
        goto LAB_1073788d;
      }
      break;
    case '\x1a':
      uVar3 = label_is_removable(pcVar6);
      if (uVar3 == 0) {
        iVar4 = label_try_remove(pcVar6);
        if (iVar4 == 0) {
          if (local_8->kind != '\x1a') goto LAB_10737663;
          label_redirect_and_delete(pcVar6,local_8);
          uVar7 = 1;
        }
        else {
          uVar7 = 1;
        }
        goto LAB_1073788d;
      }
LAB_10737663:
      if ((g_opt_global != 0) && (pcVar6->dst != (c2_operand *)0x0)) {
        pcVar5 = tuple_next_real(pcVar6);
        if ((((pcVar5 != (c2_tuple *)0x0) &&
             (((pcVar5->kind == '\x11' && ((pcVar5->u20).cond_cells == (c2_cond_cell *)0x0)) &&
              (pcVar5->op != 0x18b)))) &&
            (((pcVar5->src->kind == '\x04' &&
              (label = *(c2_tuple **)((int)&pcVar5->src->sym->u30 + 2), label != (c2_tuple *)0x0))
             && (label != pcVar6)))) && ((pcVar5->flags & 8) == 0)) {
          for (pcVar2 = pcVar6->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            if ((*(byte *)(pcVar2->rank + 9) & 8) != 0) goto switchD_1073763c_caseD_10;
          }
          label_redirect_and_delete(pcVar6,label);
          uVar7 = 1;
          goto LAB_1073788d;
        }
        if (g_jumpopt_no_crossjump == 0) {
          iVar4 = cross_jump_label_refs(pcVar6);
          if (iVar4 == 0) {
            uVar3 = sink_common_tails_of_label(pcVar6);
            goto LAB_10737814;
          }
          goto LAB_1073781c;
        }
      }
    }
switchD_1073763c_caseD_10:
    pcVar6 = local_8;
    if (local_8 == pcVar1) {
      return local_4;
    }
  } while( true );
}

