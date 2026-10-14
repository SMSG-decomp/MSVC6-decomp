void __cdecl static_init_deferred_actions(void)

{
  g_deferred_actions_head = (c1_deferred_action *)0x0;
  g_deferred_actions_tail = (c1_deferred_action *)0x0;
  g_tmpl_deduction_depth = 0;
  return;
}

