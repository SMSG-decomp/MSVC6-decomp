void __cdecl tmpl_close_parameter_scope(void)

{
  scope_pop_template_parameter_scope(g_current_scope);
  if (0 < g_template_depth) {
    g_template_depth = g_template_depth + -1;
  }
  return;
}

