void static_init_format_template_args(void)

{
  g_format_template_arg_depth = 0;
  g_format_template_arg_stack = &g_format_template_arg_anchor;
  g_format_template_arg_anchor.next = &g_format_template_arg_anchor;
  g_format_template_arg_anchor.prev = &g_format_template_arg_anchor;
  return;
}

