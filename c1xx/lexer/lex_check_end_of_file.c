void __cdecl lex_check_end_of_file(void)

{
  int iVar1;
  
  iVar1 = file_read_or_fatal();
  if (iVar1 == 0) {
    return;
  }
  if ((g_compile_flags_c4 & 0x800) != 0) {
    diag_fatal_simple(0x47);
  }
  if ((g_compile_flags_c4 & 0x1000) != 0) {
    pp_macro_location(0x39);
    return;
  }
  if ((g_compile_flags_c8 & 0x40000) != 0) {
    if ((g_compile_flags_cc & 0x10000) != 0) {
      block_list_open_or_rewind(&g_injected_text_list);
      pragma_message_text(g_injected_text_list,0x104ca538);
      lex_push_injected_text(0);
      return;
    }
    diag_fatal_simple(10);
  }
  diag_fatal_simple(4);
}

