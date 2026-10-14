void __cdecl decl_check_default_parameters_of(c1_symbol *sym)

{
  c1_function_params *params;
  
  params = *(c1_function_params **)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
  if (params->default_count != '\0') {
    decl_check_missing_default_parameter(params,sym);
  }
  return;
}

