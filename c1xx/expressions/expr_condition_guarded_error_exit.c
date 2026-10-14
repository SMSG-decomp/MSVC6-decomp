c1_node * __cdecl expr_condition_guarded_error_exit(void *null_guard,byte *frame)

{
  if (g_flow_error_jmpbuf == frame + -0x5c) {
    g_flow_error_jmpbuf = null_guard;
  }
  g_eh_context_kind = 1;
  return (c1_node *)0x0;
}

