void __cdecl expr_count_evaluated_operator(void)

{
  if (g_sizeof_depth == 0) {
    g_flow_operator_depth = g_flow_operator_depth + 1;
  }
  return;
}

