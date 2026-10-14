void __fastcall decl_function_modifier_end_parameters(int *params)

{
  int iVar1;
  
  if ((char)params[2] != '\0') {
    decl_pop_parameter_scope(g_current_scope);
  }
  if (params[1] == 6) {
    iVar1 = decl_check_old_style_formal_names((void *)*params);
    params[1] = iVar1;
  }
  return;
}

