int __cdecl type_function_param_count(c1_function_params *fn_params)

{
  if (fn_params->list->types[0] != g_type_void) {
    return fn_params->list->count;
  }
  return 0;
}

