c1_flow_state * __cdecl stmt_jump_unwind_step(c1_node **expr,c1_flow_state *rec,int mode,int target)

{
  uint uVar1;
  c1_node *pcVar2;
  c1_flow_state *pcVar3;
  int iVar4;
  c1_flow_state *pcVar5;
  
  uVar1 = rec->kind;
  switch(uVar1) {
  case 5:
    if (mode == 2) {
      pcVar2 = eh_build_exit_state_change(*expr,(int)rec->subject,rec,(c1_node *)0x0);
      *expr = pcVar2;
      pcVar3 = (c1_flow_state *)stmt_check_goto_skips_initialization_return_fragment((uint *)rec);
      return pcVar3;
    }
  default:
    return rec->prev;
  case 0xe:
    break;
  case 0x10:
    pcVar3 = func_flow_state_find(rec->prev,0xf,'\x01');
    return pcVar3;
  case 0x15:
  case 0x17:
  case 0x1d:
  case 0x21:
  case 0x2b:
  case 0x35:
    if (((int)uVar1 < 0xf) || (0x36 < (int)uVar1)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(g_token_op_flags + (uVar1 & 0xff) * 4 + 0xc4);
    }
    pcVar3 = func_flow_state_find(rec->prev,iVar4,'\x01');
    if (mode != 0) {
      for (pcVar5 = pcVar3->next;
          ((iVar4 = pcVar5->kind, iVar4 == 0x39 || (iVar4 == 0x37)) || (iVar4 == 0x38));
          pcVar5 = pcVar5->next) {
      }
      pcVar5 = func_flow_state_skip_kind_d(pcVar5);
      if (pcVar5->kind == 0xe) {
        stmt_jump_unwind_step(expr,pcVar5->next,mode,target);
      }
    }
    return pcVar3;
  }
  if (mode != 0) {
    pcVar2 = eh_walk_handler_states(*expr,rec->prev,mode,(c1_node *)0x0);
    *expr = pcVar2;
    if (((rec->flags & 2) != 0) && (mode == 2)) {
      pcVar2 = eh_build_exit_state_change(pcVar2,(int)rec->subject,rec,(c1_node *)0x0);
      *expr = pcVar2;
      pcVar3 = func_flow_state_last_of_kind_d_run(rec->prev);
      return pcVar3;
    }
    if (((rec->flags & 1) != 0) && (mode == 1)) {
      diag_error(0x16a,rec->subject,target);
    }
  }
  pcVar3 = func_flow_state_last_of_kind_d_run(rec->prev);
  return pcVar3;
}

