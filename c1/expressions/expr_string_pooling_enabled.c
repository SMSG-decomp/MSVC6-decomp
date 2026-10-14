int __cdecl expr_string_pooling_enabled(void)

{
  if ((((g_string_pooling == '\0') && (g_string_pooling_readonly_active == '\0')) ||
      ((g_current_function != (c1_symbol *)0x0 && (g_opt_cbstring != '\0')))) &&
     (((g_current_function == (c1_symbol *)0x0 || ((g_current_function->flags21 & 1) == 0)) ||
      ((g_current_function->storage & 7) == 3)))) {
    return 0;
  }
  return 1;
}

