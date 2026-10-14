c1_node * __cdecl expr_unwind_actions(c1_node *left)

{
  void **ppvVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_flow_state *pcVar4;
  uint uVar5;
  int iVar6;
  c1_flow_state *pcVar7;
  bool bVar8;
  void *pvVar9;
  int jmpbuf [16];
  c1_u8 local_18 [16];
  c1_node *local_8;
  
  if (g_flow_analysis_active != 0) {
    if (g_flow_error_jmpbuf == (void *)0x0) {
      local_8 = left;
      if (g_flow_state_abandoned != '\0') {
        return left;
      }
      g_flow_error_jmpbuf = jmpbuf;
      iVar6 = _setjmp3(jmpbuf,0);
      if (iVar6 != 0) {
        g_flow_error_jmpbuf = (void *)0x0;
        return local_8;
      }
    }
    if (g_flow_analysis_active != 0) goto LAB_104a51f9;
  }
  iVar6 = g_flow_operator_depth;
  pcVar7 = g_flow_state_top;
  if (g_flow_error_count_at_start < g_error_count) {
LAB_104a51f9:
    if (g_flow_error_jmpbuf != jmpbuf) {
      return left;
    }
    g_flow_error_jmpbuf = (void *)0x0;
    pcVar3 = expr_unwind_actions_return_arg(&stack0xfffffffc);
    return pcVar3;
  }
  uVar5 = g_flow_state_top->kind;
  switch(uVar5) {
  case 4:
    pcVar7 = g_flow_state_top->prev;
    iVar6 = pcVar7->kind;
    while (iVar6 == 0x10) {
      pcVar7 = pcVar7->prev;
      iVar6 = pcVar7->kind;
    }
    switch(pcVar7->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
      g_eh_unwind_form = '\x01';
    }
    pcVar7 = func_flow_state_find(g_flow_state_top->prev,1,'\x01');
    if (pcVar7->next->kind == 2) {
      pcVar7 = func_flow_state_find_next(pcVar7->next,3,'\x01');
      iVar6 = pcVar7->kind;
      if (iVar6 != 2) {
        do {
          if (iVar6 == 5) {
            left = eh_build_exit_state_change(left,(int)pcVar7->subject,pcVar7,(c1_node *)0x1);
          }
          pcVar7 = pcVar7->prev;
          iVar6 = pcVar7->kind;
        } while (iVar6 != 2);
        g_eh_unwind_form = '\0';
        pcVar3 = expr_unwind_actions_tail(left,&stack0xfffffffc);
        return pcVar3;
      }
    }
    g_eh_unwind_form = '\0';
    pcVar3 = expr_unwind_actions_tail(left,&stack0xfffffffc);
    return pcVar3;
  case 9:
  case 0xb:
    pcVar4 = g_flow_state_top;
    if ((g_flow_state_top != (c1_flow_state *)0x0) && (uVar5 == 9)) {
      pcVar4 = func_flow_state_find(g_flow_state_top->prev,8,'\x01');
    }
    switch(pcVar4->prev->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
      goto expr_unwind_actions_guard_exit_fragment;
    default:
      pcVar7 = pcVar7->prev;
      iVar6 = pcVar7->kind;
      while (iVar6 != 1) {
        switch(iVar6) {
        case 3:
          pcVar7 = func_flow_state_find(pcVar7->prev,2,'\0');
          break;
        case 5:
          pvVar9 = pcVar7->subject;
LAB_1042bd81:
          left = eh_build_exit_state_change(left,(int)pvVar9,pcVar7,(c1_node *)0x0);
          break;
        case 0xe:
          left = eh_walk_handler_states(left,pcVar7->prev,2,(c1_node *)0x0);
          if ((pcVar7->flags & 2) != 0) {
            pvVar9 = pcVar7->subject;
            goto LAB_1042bd81;
          }
          break;
        case 0x10:
          pcVar7 = func_flow_state_find(pcVar7->prev,0xf,'\0');
        }
        if (pcVar7 == (c1_flow_state *)0x0) break;
        pcVar7 = pcVar7->prev;
        iVar6 = pcVar7->kind;
      }
      local_18[4] = '\0';
      local_18[5] = '\0';
      local_18[6] = '\0';
      local_18[7] = '\0';
      local_18[8] = '\0';
      local_18[9] = '\0';
      local_18[10] = '\0';
      local_18[0xb] = '\0';
      local_18[0] = '\n';
      local_18[1] = '\0';
      local_18[2] = '\0';
      local_18[3] = '\0';
      local_18[0xc] = '\0';
      local_18[0xd] = '\0';
      local_18[0xe] = '\0';
      local_18[0xf] = '\0';
      func_check_flow_state_complexity(local_18,0x10);
      pcVar3 = expr_unwind_actions(left);
      pcVar3 = expr_unwind_actions_tail(pcVar3,&stack0xfffffffc);
      return pcVar3;
    }
  case 10:
    pcVar7 = func_flow_state_find(g_flow_state_top->prev,1,'\x01');
    func_flow_state_pop_record();
    if (pcVar7->next->kind == 2) {
      pcVar7 = func_flow_state_find_next(pcVar7->next,3,'\x01');
      iVar6 = pcVar7->kind;
      if (iVar6 != 2) {
        do {
          if (iVar6 == 5) {
            left = eh_build_exit_state_change(left,(int)pcVar7->subject,pcVar7,(c1_node *)0x0);
          }
          pcVar7 = pcVar7->prev;
          iVar6 = pcVar7->kind;
        } while (iVar6 != 2);
        goto code_r0x1042bf61;
      }
    }
    break;
  case 0xc:
    pcVar7 = g_flow_state_top->prev;
    if (pcVar7 != (c1_flow_state *)0x0) {
      while( true ) {
        iVar2 = pcVar7->kind;
        if ((iVar2 != 0xd) && (iVar2 != 0x3e)) goto code_r0x1042bf61;
        if (iVar2 == 0x3e) break;
        if ((pcVar7->flags & 1) == 0) {
          if ((pcVar7->flags & 2) == 0) {
            left = eh_state_marker(left,(int)pcVar7->subject,pcVar7);
          }
          else if (left == (c1_node *)0x0) {
            left = pcVar7->subject;
          }
          else {
            left = tree_new_binary_typed_right('7',left,pcVar7->subject);
          }
        }
        pcVar7 = pcVar7->prev;
        if (pcVar7 == (c1_flow_state *)0x0) {
          pcVar3 = expr_unwind_actions_tail(left,&stack0xfffffffc);
          return pcVar3;
        }
      }
      if (iVar6 != 0) {
        pcVar3 = expr_guard_collect_pending_actions(iVar6,&pcVar7->kind,left,&stack0xfffffffc);
        return pcVar3;
      }
    }
    goto code_r0x1042bf61;
  case 0x10:
    bVar8 = true;
    do {
      pcVar7 = pcVar7->prev;
      switch(pcVar7->kind) {
      case 5:
        pvVar9 = pcVar7->subject;
LAB_1042be0a:
        left = eh_build_exit_state_change(left,(int)pvVar9,pcVar7,(c1_node *)0x1);
        break;
      case 0xe:
        if (!bVar8) goto code_r0x1042bf61;
        left = eh_walk_handler_states(left,pcVar7->prev,2,(c1_node *)0x1);
        if ((pcVar7->flags & 2) != 0) {
          pvVar9 = pcVar7->subject;
          goto LAB_1042be0a;
        }
        break;
      case 0xf:
        g_eh_current_state = (int)pcVar7->subject;
        bVar8 = false;
        break;
      case 0x10:
        pcVar7 = func_flow_state_find(pcVar7->prev,0xf,'\x01');
      }
    } while (bVar8);
code_r0x1042bf61:
    if (g_flow_error_jmpbuf == jmpbuf) {
      g_flow_error_jmpbuf = (void *)0x0;
    }
    return left;
  case 0x15:
  case 0x17:
  case 0x1d:
  case 0x21:
  case 0x2b:
  case 0x35:
    if (g_flow_state_top->prev->kind != 0x10) {
      if (((int)uVar5 < 0xf) || (0x36 < (int)uVar5)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(g_token_op_flags + (uVar5 & 0xff) * 4 + 0xc4);
      }
      pcVar7 = func_flow_state_find(g_flow_state_top->prev,iVar6,'\x01');
      for (pcVar7 = pcVar7->next;
          ((iVar6 = pcVar7->kind, iVar6 == 0x39 || (iVar6 == 0x37)) || (iVar6 == 0x38));
          pcVar7 = pcVar7->next) {
      }
      pcVar7 = func_flow_state_skip_kind_d(pcVar7);
      if (pcVar7->kind == 0xe) {
        left = eh_walk_handler_states(left,pcVar7->prev,2,(c1_node *)0x1);
        if ((pcVar7->flags & 2) != 0) {
          pcVar3 = eh_build_exit_state_change(left,(int)pcVar7->subject,pcVar7,(c1_node *)0x1);
          pcVar3 = expr_unwind_actions_tail(pcVar3,&stack0xfffffffc);
          return pcVar3;
        }
        goto code_r0x1042bf61;
      }
      break;
    }
    bVar8 = g_flow_error_jmpbuf == jmpbuf;
    goto LAB_1042be30;
  case 0x39:
    if (g_pending_goto_list != (uint *)0x0) {
      ppvVar1 = &g_flow_state_top->subject;
      pcVar4 = (c1_flow_state *)g_pending_goto_list;
      do {
        if (pcVar4->subject == *ppvVar1) {
          eh_scope_setjmp_guard(pcVar4,pcVar7,1);
        }
        pcVar4 = (c1_flow_state *)pcVar4->word18;
      } while (pcVar4 != (c1_flow_state *)0x0);
    }
    break;
  case 0x3a:
    switch(g_flow_state_top->prev->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
expr_unwind_actions_guard_exit_fragment:
      bVar8 = g_flow_error_jmpbuf == jmpbuf;
      break;
    default:
      pcVar4 = stmt_find_label_flow_state(g_flow_state_top->subject);
      eh_scope_setjmp_guard(pcVar7,pcVar4,3);
      goto switchD_1042bb3b_caseD_5;
    }
LAB_1042be30:
    if (!bVar8) {
      return left;
    }
    g_flow_error_jmpbuf = (void *)0x0;
    return left;
  case 0x3c:
    pcVar7 = g_flow_state_top->prev;
    switch(pcVar7->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
      goto expr_unwind_actions_guard_exit_fragment;
    default:
      uVar5 = pcVar7->kind;
      if (uVar5 != 1) {
        do {
          switch(uVar5) {
          case 5:
            pvVar9 = pcVar7->subject;
LAB_104a5332:
            left = eh_build_exit_state_change(left,(int)pvVar9,pcVar7,(c1_node *)0x0);
            break;
          case 0xe:
            left = eh_walk_handler_states(left,pcVar7->prev,2,(c1_node *)0x0);
            if ((pcVar7->flags & 2) != 0) {
              pvVar9 = pcVar7->subject;
              goto LAB_104a5332;
            }
            break;
          case 0x10:
          case 0x1e:
          case 0x24:
          case 0x2c:
          case 0x36:
            if (((int)uVar5 < 0xf) || (0x36 < (int)uVar5)) {
              iVar6 = 0;
            }
            else {
              iVar6 = *(int *)(g_token_op_flags + (uVar5 & 0xff) * 4 + 0xc4);
            }
            pcVar7 = func_flow_state_find(pcVar7->prev,iVar6,'\x01');
            break;
          case 0x19:
          case 0x1f:
          case 0x25:
switchD_1042bf82_caseD_19:
            if (g_flow_error_jmpbuf == jmpbuf) {
              g_flow_error_jmpbuf = (void *)0x0;
            }
            return left;
          }
          pcVar7 = pcVar7->prev;
          uVar5 = pcVar7->kind;
        } while (uVar5 != 1);
        goto code_r0x1042bf61;
      }
      break;
    }
  case 0x3d:
    pcVar7 = g_flow_state_top->prev;
    switch(pcVar7->kind) {
    case 9:
    case 0xb:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
      if (g_flow_error_jmpbuf != jmpbuf) {
        return left;
      }
      g_flow_error_jmpbuf = (void *)0x0;
      return left;
    }
    uVar5 = pcVar7->kind;
    if (uVar5 != 1) {
      do {
        switch(uVar5) {
        case 5:
          left = eh_build_exit_state_change(left,(int)pcVar7->subject,pcVar7,(c1_node *)0x0);
          break;
        case 0xe:
          left = eh_walk_handler_states(left,pcVar7->prev,2,(c1_node *)0x0);
          if ((pcVar7->flags & 2) != 0) {
            pcVar3 = expr_unwind_actions_walk(0,&pcVar7->kind,left,&stack0xfffffffc);
            return pcVar3;
          }
          break;
        case 0x10:
        case 0x1e:
        case 0x24:
        case 0x2c:
        case 0x36:
          if (((int)uVar5 < 0xf) || (0x36 < (int)uVar5)) {
            iVar6 = 0;
          }
          else {
            iVar6 = *(int *)(g_token_op_flags + (uVar5 & 0xff) * 4 + 0xc4);
          }
          pcVar7 = func_flow_state_find(pcVar7->prev,iVar6,'\x01');
          break;
        case 0x19:
        case 0x1f:
        case 0x25:
        case 0x31:
          goto switchD_1042bf82_caseD_19;
        }
        pcVar7 = pcVar7->prev;
        uVar5 = pcVar7->kind;
      } while (uVar5 != 1);
      goto code_r0x1042bf61;
    }
  }
switchD_1042bb3b_caseD_5:
  pcVar3 = expr_unwind_actions_tail(left,&stack0xfffffffc);
  return pcVar3;
}

