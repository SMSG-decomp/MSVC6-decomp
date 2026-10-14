c1_node * __cdecl
expr_unwind_actions_case5_fragment(int walking,int *rec,c1_node *result,byte *frame)

{
  byte bVar1;
  void *name;
  
code_r0x104a525d:
  name = ((c1_flow_state *)rec)->subject;
LAB_1042be0a:
  result = eh_build_exit_state_change(result,(int)name,(c1_flow_state *)rec,(c1_node *)0x1);
  *(c1_node **)(frame + 8) = result;
switchD_1042bdc3_caseD_6:
  if (walking == 0) {
expr_unwind_actions_tail:
    if (g_flow_error_jmpbuf == frame + -0x54) {
      g_flow_error_jmpbuf = (void *)0x0;
    }
    return result;
  }
  rec = &((c1_flow_state *)rec)->prev->kind;
  switch(((c1_flow_state *)rec)->kind) {
  case 5:
    goto code_r0x104a525d;
  default:
    goto switchD_1042bdc3_caseD_6;
  case 0xe:
    break;
  case 0xf:
    g_eh_current_state = (int)((c1_flow_state *)rec)->subject;
    walking = 0;
    goto switchD_1042bdc3_caseD_6;
  case 0x10:
    rec = &func_flow_state_find(((c1_flow_state *)rec)->prev,0xf,'\x01')->kind;
    goto switchD_1042bdc3_caseD_6;
  }
  if (walking == 0) goto expr_unwind_actions_tail;
  result = eh_walk_handler_states(result,((c1_flow_state *)rec)->prev,2,(c1_node *)0x1);
  bVar1 = ((c1_flow_state *)rec)->flags;
  *(c1_node **)(frame + 8) = result;
  if ((bVar1 & 2) != 0) goto code_r0x1042be03;
  goto switchD_1042bdc3_caseD_6;
code_r0x1042be03:
  name = ((c1_flow_state *)rec)->subject;
  goto LAB_1042be0a;
}

