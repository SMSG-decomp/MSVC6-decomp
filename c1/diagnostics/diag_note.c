void __cdecl diag_note(int n,...)

{
  va_list args;
  
  if ((g_compile_flags_c8 & 0x20000) == 0) {
    args = &stack0x00000008;
    diag_begin(&g_diag_message_list,g_token_position);
    diag_message_list_add(&g_diag_message_list,6000,(short)(n % 1000) + 6000,(char *)&args);
    diag_end(&g_diag_message_list);
  }
  return;
}

