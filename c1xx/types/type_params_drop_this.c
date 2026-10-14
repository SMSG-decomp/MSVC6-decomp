c1_function_params * __cdecl type_params_drop_this(c1_function_params *params)

{
  params->this_type = (c1_type *)0x0;
  params->flags = params->flags & 0xfe;
  return params;
}

