void __cdecl eh_enter_new_expression_region(void)

{
  list_push_in_arena((int *)&g_eh_new_region_base_stack,4);
  g_eh_new_region_base_stack->value = g_eh_new_region_base_state;
  g_eh_new_region_base_state = g_eh_current_state;
  list_push_in_arena((int *)&g_eh_state_stack,4);
  g_eh_state_stack->value = g_eh_context_kind;
  g_eh_context_kind = 4;
  list_push_in_arena((int *)&g_eh_init_target_stack,4);
  g_eh_init_target_stack->sym = PTR_104d2c58;
  PTR_104d2c58 = (c1_symbol *)0x0;
  g_init_target_is_reference = '\0';
  return;
}

