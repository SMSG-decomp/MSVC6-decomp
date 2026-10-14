void __cdecl diag_fatal(int n,...)

{
  va_list args;
  
  c1_set_phase(7);
  if ((((n == 0x3b) || (n == 0x3c)) || (n == 0x3f)) || (n == 0x4c)) {
    pp_warn_include_depth();
  }
  args = &stack0x00000008;
  diag_begin(&g_diag_message_list,g_token_position);
  diag_message_list_add(&g_diag_message_list,1000,(short)n + 1000,(char *)&args);
  diag_end(&g_diag_message_list);
  args = (va_list)0x0;
  c1_abort_cleanup();
  if (n == 0x5c) {
    c1_raise_exit(0xf101);
  }
  g_error_count = g_error_count + 1;
  c1_raise_exit(g_error_count);
}

