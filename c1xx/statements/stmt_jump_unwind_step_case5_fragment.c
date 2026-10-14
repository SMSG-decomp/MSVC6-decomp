uint __cdecl stmt_jump_unwind_step_case5_fragment(uint *rec,c1_node **expr,int mode)

{
  c1_node *pcVar1;
  uint uVar2;
  
  if (mode == 2) {
    pcVar1 = eh_build_exit_state_change(*expr,rec[4],(c1_flow_state *)rec,(c1_node *)0x0);
    *expr = pcVar1;
    uVar2 = stmt_check_goto_skips_initialization_return_fragment(rec);
    return uVar2;
  }
  return rec[3];
}

