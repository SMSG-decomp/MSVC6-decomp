c1_node * __cdecl
flow_walk_object_state_change_fragment(int zero,int *rec,c1_node *result,byte *frame)

{
  byte bVar1;
  uint uVar2;
  int kind;
  void *name;
  
code_r0x104a532c:
  name = ((c1_flow_state *)rec)->subject;
LAB_104a5332:
  result = eh_build_exit_state_change(result,(int)name,(c1_flow_state *)rec,(c1_node *)zero);
  *(c1_node **)(frame + 8) = result;
switchD_1042bf1e_caseD_6:
  rec = &((c1_flow_state *)rec)->prev->kind;
  uVar2 = ((c1_flow_state *)rec)->kind;
  if (uVar2 == 1) {
    if (g_flow_error_jmpbuf == frame + -0x54) {
      g_flow_error_jmpbuf = (void *)0x0;
    }
    return result;
  }
  switch(uVar2) {
  case 5:
    goto code_r0x104a532c;
  default:
    goto switchD_1042bf1e_caseD_6;
  case 0xe:
    break;
  case 0x10:
  case 0x1e:
  case 0x24:
  case 0x2c:
  case 0x36:
    if (((int)uVar2 < 0xf) || (0x36 < (int)uVar2)) {
      kind = 0;
    }
    else {
      kind = *(int *)(g_token_op_flags + (uVar2 & 0xff) * 4 + 0xc4);
    }
    rec = &func_flow_state_find(((c1_flow_state *)rec)->prev,kind,'\x01')->kind;
    goto switchD_1042bf1e_caseD_6;
  case 0x19:
  case 0x1f:
  case 0x25:
    if (g_flow_error_jmpbuf == frame + -0x54) {
      g_flow_error_jmpbuf = (void *)zero;
    }
    return result;
  }
  result = eh_walk_handler_states(result,((c1_flow_state *)rec)->prev,2,(c1_node *)zero);
  bVar1 = ((c1_flow_state *)rec)->flags;
  *(c1_node **)(frame + 8) = result;
  if ((bVar1 & 2) != 0) goto code_r0x104a5365;
  goto switchD_1042bf1e_caseD_6;
code_r0x104a5365:
  name = ((c1_flow_state *)rec)->subject;
  goto LAB_104a5332;
}

