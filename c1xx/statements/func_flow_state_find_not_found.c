c1_flow_state * __cdecl func_flow_state_find_not_found(char longjmp_if_missing)

{
  if ((longjmp_if_missing != '\0') && (g_flow_error_jmpbuf != (void *)0x0)) {
    func_flow_state_reset();
    g_flow_state_abandoned = '\x01';
    longjmp(g_flow_error_jmpbuf,-1);
  }
  return (c1_flow_state *)0x0;
}

