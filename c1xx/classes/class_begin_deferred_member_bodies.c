void class_begin_deferred_member_bodies(void)

{
  c1_deferred_body_list *pcVar1;
  
  pcVar1 = g_deferred_member_bodies;
  if ((((g_class_depth < 0) && (g_paren_depth < 1)) &&
      (g_deferred_member_bodies != (c1_deferred_body_list *)0x0)) &&
     (g_deferred_member_bodies->first != (c1_deferred_body *)0x0)) {
    if ((g_class_syntax_error_count == 0) && (g_opt_Zg == '\0')) {
      g_deferred_member_bodies->cursor = g_deferred_member_bodies->first;
      class_default_args_begin_next_member();
      return;
    }
    g_class_syntax_error_count = 0;
    g_deferred_member_bodies->cursor = (c1_deferred_body *)0x0;
    pcVar1->first = (c1_deferred_body *)0x0;
    if (g_deferred_member_bodies->outer == (c1_deferred_body_list *)0x0) {
      g_deferred_member_bodies = (c1_deferred_body_list *)0x0;
    }
  }
  return;
}

