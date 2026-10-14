void __cdecl class_reset_member_function_class(void)

{
  if (((g_class_depth < 0) && (g_paren_depth < 1)) && (g_current_function == (c1_symbol *)0x0)) {
    g_member_function_class = (c1_symbol *)0x0;
    g_qualified_lookup_found_overloads = 1;
  }
  return;
}

