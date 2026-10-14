void free_list_pop_124c(void)

{
  if (*g_type_emission_stack != (c1_symbol_stack_node *)0x0) {
    *g_type_emission_stack = (*g_type_emission_stack)->next;
  }
  return;
}

