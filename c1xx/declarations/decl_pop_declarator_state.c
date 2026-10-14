void __fastcall decl_pop_declarator_state(c1_param_clause *clause)

{
  if (clause->pop_scope != '\0') {
    scope_pop_if_kind1(g_current_scope);
  }
  clause->defaults = g_paren_level_arg_lists[g_paren_depth + 1];
  g_paren_level_arg_lists[g_paren_depth + 1] = (c1_arg_list *)0x0;
  return;
}

