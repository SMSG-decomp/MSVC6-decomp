void func_flow_state_pop_record(void)

{
  c1_flow_state *pcVar1;
  
  pcVar1 = g_flow_state_top->prev;
  g_flow_state_top->prev = g_flow_state_free_list;
  g_flow_state_top->next = (c1_flow_state *)0x0;
  if (g_flow_state_free_list != (c1_flow_state *)0x0) {
    g_flow_state_free_list->next = g_flow_state_top;
  }
  g_flow_state_free_list = g_flow_state_top;
  if (pcVar1 != (c1_flow_state *)0x0) {
    g_flow_state_top = pcVar1;
    pcVar1->next = (c1_flow_state *)0x0;
    g_flow_state_depth = g_flow_state_depth + -1;
    return;
  }
  g_flow_state_top = (c1_flow_state *)0x0;
  g_flow_state_bottom = (c1_flow_state *)0x0;
  g_flow_state_depth = g_flow_state_depth + -1;
  return;
}

