c1_node * expr_check_this_usage(void)

{
  c1_node *pcVar1;
  
  if ((((g_compile_flags_c4 & 0x20000) != 0) || ((g_compile_flags_c8 & 0x100) != 0)) &&
     ((g_compile_flags_c4 & 0x20) == 0)) {
    if ((g_compile_flags_c8 & 0x100) != 0) {
      if (g_ms_extensions != '\0') {
        diag_warning(1,0x163);
        pcVar1 = expr_this_pointer((c1_symbol *)0x0);
        return pcVar1;
      }
      diag_warning(4,0x163);
    }
    pcVar1 = expr_this_pointer((c1_symbol *)0x0);
    return pcVar1;
  }
  diag_error(0x163);
  return (c1_node *)0x0;
}

