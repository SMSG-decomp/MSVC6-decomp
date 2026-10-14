c1_node * __cdecl expr_unwind_actions_guard_exit_fragment(int zero,byte *frame)

{
  if (g_flow_error_jmpbuf != frame + -0x54) {
    return *(c1_node **)(frame + 8);
  }
  g_flow_error_jmpbuf = (void *)zero;
  return *(c1_node **)(frame + 8);
}

