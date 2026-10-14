void func_flow_state_drop_kind_d(void)

{
  if (g_flow_state_abandoned == '\0') {
    while (g_flow_state_top != (c1_flow_state *)0x0) {
      if (g_flow_state_top->kind != 0xd) {
        if (g_flow_state_top == (c1_flow_state *)0x0) {
          return;
        }
        if (g_flow_state_top->kind != 0x12) {
          return;
        }
        func_flow_state_pop_record();
        func_flow_state_pop_record();
        return;
      }
      func_flow_state_pop_record();
    }
  }
  return;
}

