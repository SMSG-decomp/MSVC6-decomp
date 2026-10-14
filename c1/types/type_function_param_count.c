int __cdecl type_function_param_count(c1_param_list *params)

{
  if (params->types[0] != g_type_void) {
    return params->count;
  }
  return 0;
}

