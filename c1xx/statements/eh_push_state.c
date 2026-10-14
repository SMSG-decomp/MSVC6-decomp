void __cdecl eh_push_state(void)

{
  list_push_in_arena((int *)&g_eh_state_stack,4);
  g_eh_state_stack->value = g_eh_context_kind;
  g_eh_context_kind = 3;
  g_eh_region_base_state = g_eh_current_state;
  return;
}

