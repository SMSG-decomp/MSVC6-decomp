void __cdecl eh_enter_try(void)

{
  g_eh_try_depth = g_eh_try_depth + 1;
  g_eh_ctor_return_flushed = '\0';
  list_push_in_arena((int *)&g_eh_state_stack,4);
  g_eh_state_stack->value = g_eh_context_kind;
  g_eh_context_kind = 2;
  g_eh_region_base_state = g_eh_current_state;
  return;
}

