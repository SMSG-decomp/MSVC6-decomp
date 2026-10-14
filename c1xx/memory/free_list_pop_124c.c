void __cdecl free_list_pop_124c(void)

{
  if (*g_type_emission_stack != (c1_type_emission_cell *)0x0) {
    *g_type_emission_stack = (*g_type_emission_stack)->next;
  }
  return;
}

