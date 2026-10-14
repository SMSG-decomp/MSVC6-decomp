void __cdecl paren_depth_leave(int value)

{
  if (0 < g_paren_depth) {
    g_paren_depth = g_paren_depth + -1;
    g_reparsed_template_args = (c1_arg_list *)value;
    return;
  }
  g_reparsed_template_args = (c1_arg_list *)value;
  return;
}

