c1_function_params * __cdecl type_params_make_static(c1_function_params *params)

{
  params->flags = params->flags | 1;
  return params;
}

