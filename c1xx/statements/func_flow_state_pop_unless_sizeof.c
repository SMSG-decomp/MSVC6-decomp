void __cdecl func_flow_state_pop_unless_sizeof(void)

{
  if (g_sizeof_depth == 0) {
    func_flow_state_pop_record();
    g_flow_operator_depth = g_flow_operator_depth + -1;
  }
  return;
}

