void __cdecl func_flow_state_release(c1_flow_state *rec)

{
  c1_flow_state *pcVar1;
  
  pcVar1 = rec->next;
  if (pcVar1 != (c1_flow_state *)0x0) {
    if (rec->prev != (c1_flow_state *)0x0) {
      rec->prev->next = pcVar1;
      pcVar1 = g_flow_state_bottom;
    }
    g_flow_state_bottom = pcVar1;
    rec->next->prev = rec->prev;
    rec->prev = g_flow_state_free_list;
    rec->next = (c1_flow_state *)0x0;
    if (g_flow_state_free_list != (c1_flow_state *)0x0) {
      g_flow_state_free_list->next = rec;
    }
    g_flow_state_free_list = rec;
    return;
  }
  pcVar1 = g_flow_state_top->prev;
  g_flow_state_top->prev = g_flow_state_free_list;
  g_flow_state_top->next = (c1_flow_state *)0x0;
  if (g_flow_state_free_list != (c1_flow_state *)0x0) {
    g_flow_state_free_list->next = g_flow_state_top;
  }
  g_flow_state_free_list = g_flow_state_top;
  if (pcVar1 == (c1_flow_state *)0x0) {
    g_flow_state_top = (c1_flow_state *)0x0;
    g_flow_state_bottom = (c1_flow_state *)0x0;
    g_flow_state_depth = g_flow_state_depth + -1;
    return;
  }
  g_flow_state_top = pcVar1;
  pcVar1->next = (c1_flow_state *)0x0;
  g_flow_state_depth = g_flow_state_depth + -1;
  return;
}

