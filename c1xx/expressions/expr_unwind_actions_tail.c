c1_node * __cdecl expr_unwind_actions_tail(c1_node *result,byte *frame)

{
  if (g_flow_error_jmpbuf == frame + -0x54) {
    g_flow_error_jmpbuf = (void *)0x0;
  }
  return result;
}

