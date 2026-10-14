void parse_paren_depth_pop(void)

{
  if (0 < g_paren_depth) {
    g_paren_depth = g_paren_depth + -1;
  }
  return;
}

