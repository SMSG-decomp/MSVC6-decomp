c1_node * __cdecl
expr_guard_collect_pending_actions(int operator_depth,int *rec,c1_node *result,byte *frame)

{
  int iVar1;
  c1_node *pcVar2;
  
  while( true ) {
    rec = &((c1_flow_state *)rec)->prev->kind;
    if ((c1_flow_state *)rec == (c1_flow_state *)0x0) {
      pcVar2 = expr_unwind_actions_tail(result,frame);
      return pcVar2;
    }
    iVar1 = ((c1_flow_state *)rec)->kind;
    if ((iVar1 != 0xd) && (iVar1 != 0x3e)) break;
    if (iVar1 == 0x3e) {
      if (operator_depth + -1 != 0) {
        pcVar2 = expr_guard_collect_pending_actions(operator_depth + -1,rec,result,frame);
        return pcVar2;
      }
      break;
    }
    if ((((c1_flow_state *)rec)->flags & 1) == 0) {
      if ((((c1_flow_state *)rec)->flags & 2) == 0) {
        result = eh_state_marker(result,(int)((c1_flow_state *)rec)->subject,(c1_flow_state *)rec);
      }
      else if (result == (c1_node *)0x0) {
        result = ((c1_flow_state *)rec)->subject;
      }
      else {
        result = tree_new_binary_typed_right('7',result,((c1_flow_state *)rec)->subject);
      }
      *(c1_node **)(frame + 8) = result;
    }
  }
  if (g_flow_error_jmpbuf == frame + -0x54) {
    g_flow_error_jmpbuf = (void *)0x0;
  }
  return result;
}

