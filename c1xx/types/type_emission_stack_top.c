c1_symbol * __cdecl type_emission_stack_top(void)

{
  if ((g_type_emission_stack != (c1_type_emission_cell **)0x0) &&
     (*g_type_emission_stack != (c1_type_emission_cell *)0x0)) {
    return (*g_type_emission_stack)->sym;
  }
  return (c1_symbol *)0x0;
}

