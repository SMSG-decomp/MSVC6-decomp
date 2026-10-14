void __cdecl func_flow_state_reset_if_used(void)

{
  if ((g_flow_state_bottom == (c1_flow_state *)0x0) &&
     (g_flow_state_free_list == (c1_flow_state *)0x0)) {
    return;
  }
  g_flow_state_free_list = (c1_flow_state *)0x0;
  g_flow_state_bottom = (c1_flow_state *)0x0;
  g_flow_state_top = (c1_flow_state *)0x0;
  g_flow_state_function_record = (c1_flow_state *)0x0;
  g_flow_operator_depth = 0;
  g_flow_state_depth = 0;
  g_flow_goto_count = 0;
  g_defined_label_flow_states = (c1_flow_state *)0x0;
  g_pending_goto_list = (uint *)0x0;
  g_flow_switch_record = (c1_flow_state *)0x0;
  PTR_104d2c58 = (c1_symbol *)0x0;
  g_init_target_is_reference = '\0';
  g_init_member_store_active = 0;
  g_brace_init_active = 0;
  g_eh_last_state = -1;
  g_eh_current_state = -1;
  g_eh_state_table = (c1_eh_state *)0x0;
  g_eh_context_kind = 1;
  g_eh_state_capacity = 0x80;
  return;
}

