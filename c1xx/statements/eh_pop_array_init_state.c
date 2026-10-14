void __cdecl eh_pop_array_init_state(void)

{
  g_init_declaration_depth = g_init_declaration_depth + -1;
  if (g_eh_array_init_symbol != (c1_symbol *)0x0) {
    g_eh_previous_state = g_eh_array_init_state;
    g_eh_context_kind = g_eh_state_stack->value;
    list_pop_head((int *)&g_eh_state_stack);
    g_eh_array_init_symbol = (c1_symbol *)0x0;
  }
  return;
}

